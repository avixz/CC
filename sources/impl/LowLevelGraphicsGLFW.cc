//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.cc
//---------------------------------------------------------------------------

#include <string>
#include "impl/LowLevelGraphicsGLFW.h"

namespace CC
{
  //---------------------------------------------------------------------------
  bool LowLevelGraphicsGLFW::Init(int width, int height,
      const std::string& windowCaption)
  {
    if (!glfwInit()) 
    {
      return false;
    }
    m_window = glfwCreateWindow(width, height, windowCaption.c_str(),
        NULL, NULL);

    if (!m_window)
    {
      glfwTerminate();
      return false;
    }
    //glfwMakeContextCurrent(window);

    SetupGL();
  }

  //---------------------------------------------------------------------------
  void LowLevelGraphicsGLFW::SetupGL()
  {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  //---------------------------------------------------------------------------
  GLFWwindow* LowLevelGraphicsGLFW::getWindow()
  {
    return m_window;
  }
}
