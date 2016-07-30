//---------------------------------------------------------------------------
// ILowLevelGraphics.h
//---------------------------------------------------------------------------

#pragma once

#include <string>

namespace CC
{
  /** ILowLevelGraphics
   */
  class ILowLevelGraphics
  {
    public:
      virtual bool Init(int width, int height, const std::string& windowCaption) = 0;
  };
}
