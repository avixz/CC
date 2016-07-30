//---------------------------------------------------------------------------
// Graphics.h
//---------------------------------------------------------------------------

#pragma once

#include <string>

namespace CC
{
  class ILowLevelGraphics;

  class Graphics
  {
    public:

      Graphics(ILowLevelGraphics* lowLevelGraphics);

      bool Init(int width, int height, const std::string& windowCaption);

    private:

      ILowLevelGraphics* m_lowLevelGraphics;
  };
}
