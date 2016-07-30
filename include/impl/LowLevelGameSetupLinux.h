//---------------------------------------------------------------------------
// LowLevelGameSetupLinux.h
//---------------------------------------------------------------------------

#pragma once

#include "game/ILowLevelGameSetup.h"

namespace CC
{
  // Forward declarations
  class Input;
  class System;
  class Graphics;
  class ILowLevelSystem;
  class LowLevelGraphicsGLFW;
  class ILowLevelInput;

  /** LowLevelGameSetupLinux
   */
  class LowLevelGameSetupLinux : public ILowLevelGameSetup
  {
    public:
      LowLevelGameSetupLinux();
      ~LowLevelGameSetupLinux();

      Input* CreateInput();
      System* CreateSystem();
      Graphics* CreateGraphics();

    private:
      ILowLevelSystem* m_lowLevelSystem;
      LowLevelGraphicsGLFW* m_lowLevelGraphics;
      ILowLevelInput* m_lowLevelInput;
  };
}
