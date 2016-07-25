//---------------------------------------------------------------------------
// LowLevelGameSetupLinux.cc
//---------------------------------------------------------------------------

#include "impl/LowLevelSystemLinux.h"
#include "impl/LowLevelGraphicsGLFW.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/LowLevelGameSetupLinux.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelGameSetupLinux::LowLevelGameSetupLinux()
  {
    m_lowLevelSystem = new LowLevelSystemLinux();
    m_lowLevelGraphics = new LowLevelGraphicsGLFW();
    m_lowLevelInput = new LowLevelInputGLFW(m_lowLevelGraphics);
  }

  //---------------------------------------------------------------------------
  LowLevelGameSetupLinux::~LowLevelGameSetupLinux()
  {
    delete m_lowLevelInput;
    delete m_lowLevelGraphics;
    delete m_lowLevelSystem;
  }
}
