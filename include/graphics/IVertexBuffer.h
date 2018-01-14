//---------------------------------------------------------------------------
// IVertexBuffer.h
//---------------------------------------------------------------------------

#pragma once

#include "math/MathTypes.h"

namespace CC
{
  class IVertexBuffer
  {
    public:
      virtual void AddVertex(const Vector3f& vertex) = 0;
      virtual void Bind() = 0;
      virtual void UnBind() = 0;
      virtual void Compile() = 0;
      virtual void Draw() = 0;
  };
}
