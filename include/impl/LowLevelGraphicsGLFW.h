//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "graphics/ILowLevelGraphics.h"

namespace CC
{
  class LowLevelGraphicsGLFW : public ILowLevelGraphics
  {
    public:
      LowLevelGraphicsGLFW();
      bool Init(int width, int height, const std::string& windowCaption);
      IVertexBuffer* CreateVertexBuffer();
      void SetupGL();
      GLFWwindow* getWindow();

    private:
      GLFWwindow* m_window;
  };
}
