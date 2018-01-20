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
  class IShaderProgram;
}

namespace CC
{
  /** ILowLevelGraphics
   */
  class ILowLevelGraphics
  {
    public:
      virtual bool Init(int width, int height, const std::string& windowCaption) = 0;
      virtual void SwapBuffers() = 0;
      virtual IVertexBuffer* CreateVertexBuffer() = 0;
      virtual IShaderProgram* CreateShaderProgram(const std::string& vertexShaderSource,
                                                  const std::string& fragmentShaderSource) = 0;
  };
}
