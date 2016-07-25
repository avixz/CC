//---------------------------------------------------------------------------
// LowLevelGraphicsGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include <string>
#include "GLFW/glfw3.h"
#include "graphics/ILowLevelGraphics.h"

namespace CC
{
  class LowLevelGraphicsGLFW : public ILowLevelGraphics
  {
    public:
      bool Init(int width, int height, const std::string& windowCaption);
      void SetupGL();
      GLFWwindow* getWindow();

    private:
      GLFWwindow* m_window;
  };
}
