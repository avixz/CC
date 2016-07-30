//---------------------------------------------------------------------------
// Graphics.cc
//---------------------------------------------------------------------------

#include "graphics/ILowLevelGraphics.h"
#include "graphics/Graphics.h"

namespace CC
{
  //-------------------------------------------------------------------------
  Graphics::Graphics(ILowLevelGraphics* lowLevelGraphics) :
    m_lowLevelGraphics(lowLevelGraphics)
  {
  }
}
