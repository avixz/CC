//---------------------------------------------------------------------------
// VertexBufferVBO.cc
//---------------------------------------------------------------------------

#include "GL/glew.h"
#include "system/ILowLevelSystem.h"
#include "impl/VertexBufferVBO.h"

namespace CC
{
  void VertexBufferVBO::AddVertex(const Vector3f& vertex)
  {
    m_vertexArray.push_back(vertex);
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Bind()
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    Log("VBO bound\n");
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::UnBind()
  {
    glDisableVertexAttribArray(0);
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Compile()
  {
    // Create VBO vertex arrays
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ARRAY_BUFFER, m_vertexArray.size() * sizeof(float), &m_vertexArray[0], GL_STATIC_DRAW);
    Log("VBO compiled\n");
  }

  //-------------------------------------------------------------------------
  void VertexBufferVBO::Draw()
  {
    glDrawArrays(GL_POINTS, 0, 1);
    Log("VBO drawn\n");
  }
}
