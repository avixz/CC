//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.cc
//---------------------------------------------------------------------------

#include <string>
#include "impl/VertexBufferVBO.h"
#include "impl/LowLevelGraphicsGLFW.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelGraphicsGLFW::LowLevelGraphicsGLFW()
  {
  }

  //---------------------------------------------------------------------------
  bool LowLevelGraphicsGLFW::Init(int width, int height,
      const std::string& windowCaption)
  {
    if (!glfwInit()) 
    {
      return false;
    }
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    m_window = glfwCreateWindow(width, height, windowCaption.c_str(),
        NULL, NULL);

    if (!m_window)
    {
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(m_window);

    // Must be done after GLFW is initialized and context is current
    GLenum result = glewInit();
    if (result != GLEW_OK)
    {
      return false;
    }

    SetupGL();
    glfwSwapBuffers(m_window);

    return true;
  }

  //---------------------------------------------------------------------------
  IVertexBuffer* LowLevelGraphicsGLFW::CreateVertexBuffer()
  {
    return new VertexBufferVBO();
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::SetupGL()
  {
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  //---------------------------------------------------------------------------
  GLFWwindow* LowLevelGraphicsGLFW::getWindow()
  {
    return m_window;
  }
}
