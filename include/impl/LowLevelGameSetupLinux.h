//---------------------------------------------------------------------------
// LowLevelGameSetupLinux.h
//---------------------------------------------------------------------------

#pragma once

#include "game/ILowLevelGameSetup.h"

namespace CC
{
  // Forward declarations
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

    private:
      ILowLevelSystem* m_lowLevelSystem;
      LowLevelGraphicsGLFW* m_lowLevelGraphics;
      ILowLevelInput* m_lowLevelInput;
  };
}
