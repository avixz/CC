//---------------------------------------------------------------------------
// Game.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  /** LowLevelGameSetup
   */
  class ILowLevelGameSetup;
  class Graphics;
  class System;
  class Input;
  class Updater;

  /** Game
   */
  class Game
  {
    public:
      Game(ILowLevelGameSetup* lowLevelGameSetup, int width, int height);

      void Run();
      void Exit();
      Updater* GetUpdater();
      Input* GetInput();
      Graphics* GetGraphics();

    private:
      void GameInit(ILowLevelGameSetup* lowLevelGameSetup);

      ILowLevelGameSetup *m_lowLeveGameSetup;
      Graphics* m_graphics;
      System* m_system;
      Input* m_input;
      Updater* m_updater;
      bool m_exit;
  };
}
