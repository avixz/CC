//---------------------------------------------------------------------------
// VertexBufferVBO.h
//---------------------------------------------------------------------------

#pragma once

#include <vector>
#include "graphics/IVertexBuffer.h"

namespace CC
{
  class VertexBufferVBO : public IVertexBuffer
  {
    public:
      virtual void AddVertex(const Vector3f& vertex);
      virtual void Bind();
      virtual void UnBind();
      virtual void Compile();
      virtual void Draw();

    private:
      std::vector<Vector3f> m_vertexArray;
      unsigned int m_handle;
  };
}
