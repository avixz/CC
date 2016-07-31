//---------------------------------------------------------------------------
// Game.cc
//---------------------------------------------------------------------------

#include "game/Game.h"

//TODO: Remove this
#include "input/IKeyboard.h"

#include "game/ILowLevelGameSetup.h"

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
    m_lowLeveGameSetup = lowLevelGameSetup;

    m_system = lowLevelGameSetup->CreateSystem();

    m_graphics = lowLevelGameSetup->CreateGraphics();
    m_graphics->Init(800, 600, "Hello World!");

    m_input = lowLevelGameSetup->CreateInput();
  }

  //-------------------------------------------------------------------------
  void Game::Run()
  {
    bool exit = false;

    while (!exit)
    {
      m_input->Update(0);
      exit = m_input->m_keyboard->KeyIsPressed();
    }
  }
}
