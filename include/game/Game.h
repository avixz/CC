//---------------------------------------------------------------------------
// Game.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  /** LowLevelGameSetup
   */
  class ILowLevelGameSetup;

  /** Game
   */
  class Game
  {
    public:
      Game(ILowLevelGameSetup* gameSetup, int width, int height);
  };
}
