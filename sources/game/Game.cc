//---------------------------------------------------------------------------
// Game.cc
//---------------------------------------------------------------------------

#include "game/Game.h"

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

    m_graphics = lowLevelGameSetup->CreateGraphics();
    m_system = lowLevelGameSetup->CreateSystem();
    m_input = lowLevelGameSetup->CreateInput();

    m_graphics->Init(800, 600, "Hello World!");
  }
}
