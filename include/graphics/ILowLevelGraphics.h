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
      virtual ~ILowLevelGraphics(){};

      virtual bool Init(int width, int height, const std::string& windowCaption);
  };
}
