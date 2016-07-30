//---------------------------------------------------------------------------
// Graphics.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  class ILowLevelGraphics;

  class Graphics
  {
    public:

      Graphics(ILowLevelGraphics* lowLevelGraphics);

    private:

      ILowLevelGraphics* m_lowLevelGraphics;
  };
}
