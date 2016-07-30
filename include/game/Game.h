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

  /** Game
   */
  class Game
  {
    public:
      Game(ILowLevelGameSetup* lowLevelGameSetup, int width, int height);

    private:
      void GameInit(ILowLevelGameSetup* lowLevelGameSetup);

      ILowLevelGameSetup *m_lowLeveGameSetup;
      Graphics* m_graphics;
      System* m_system;
      Input* m_input;
  };
}
