//---------------------------------------------------------------------------
// ILowLevelGraphics.h
//---------------------------------------------------------------------------

#pragma once

#include <string>

/**
 * Fwd Declarations
 */
namespace CC
{
  class IVertexBuffer;
}

namespace CC
{
  /** ILowLevelGraphics
   */
  class ILowLevelGraphics
  {
    public:
      virtual bool Init(int width, int height, const std::string& windowCaption) = 0;
      virtual IVertexBuffer* CreateVertexBuffer() = 0;
  };
}
