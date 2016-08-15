//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.cc
//---------------------------------------------------------------------------

#include <string>
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
    m_window = glfwCreateWindow(width, height, "asdf",
        NULL, NULL);

    if (!m_window)
    {
      glfwTerminate();
      return false;
    }
    glfwMakeContextCurrent(m_window);

    SetupGL();

    glfwSwapBuffers(m_window);

    return true;
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
