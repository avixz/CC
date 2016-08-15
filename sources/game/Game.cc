//---------------------------------------------------------------------------
// Game.cc
//---------------------------------------------------------------------------


//TODO: Remove this
#ifdef EMSC
#include <emscripten/emscripten.h>
void doFrame() {};
#endif
#include "input/IKeyboard.h"

#include "game/ILowLevelGameSetup.h"
#include "system/ILowLevelSystem.h"

#include "game/Game.h"

namespace CC
{
  //-------------------------------------------------------------------------
  Game::Game(ILowLevelGameSetup* lowLevelGameSetup, int width, int height)
  {
    GameInit(lowLevelGameSetup);
  }

  //-------------------------------------------------------------------------
  void Game::GameInit(ILowLevelGameSetup* lowLevelGameSetup)
  {
    Log("Creating Engine Modules\n");
    Log("--------------------------------------------------------\n");

    m_lowLeveGameSetup = lowLevelGameSetup;

    Log(" Creating system module\n");
    m_system = lowLevelGameSetup->CreateSystem();

    Log(" Creating graphics module\n");
    m_graphics = lowLevelGameSetup->CreateGraphics();
    m_graphics->Init(800, 600, "Hello World!");

    Log(" Creating input module\n");
    m_input = lowLevelGameSetup->CreateInput();
  }

  //-------------------------------------------------------------------------
  void Game::Run()
  {
    bool exit = false;
    unsigned int time = GetApplicationTime();

#ifdef EMSC
    emscripten_set_main_loop(doFrame, 0, 1);
#else
    while (!exit)
    {
      unsigned int oldTime = time;
      time = GetApplicationTime();
      unsigned int delta = time - oldTime;

      Log("%u ms\n", delta);

      for (int i = 0; i < 1000000; ++i);

      m_input->Update(0);
      exit = m_input->m_keyboard->KeyIsPressed();
    }
#endif
  }
}
