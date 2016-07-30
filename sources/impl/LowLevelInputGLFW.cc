//---------------------------------------------------------------------------
// LowLevelInputGLFW.cc
//---------------------------------------------------------------------------

#include "GLFW/glfw3.h"

#define GLEQ_IMPLEMENTATION
#include "gleq.h"

#include "impl/LowLevelGraphicsGLFW.h"
#include "input/IKeyboard.h"
#include "impl/LowLevelInputGLFW.h"

namespace CC
{
  //---------------------------------------------------------------------------
  LowLevelInputGLFW::LowLevelInputGLFW(LowLevelGraphicsGLFW* lowLevelGraphics) :
    m_lowLevelGraphics(lowLevelGraphics)
  {
    gleqTrackWindow(lowLevelGraphics->getWindow());
  }

  //---------------------------------------------------------------------------
  void LowLevelInputGLFW::BeginInputUpdate()
  {
    glfwPollEvents();
    GLEQevent event;

    while (gleqNextEvent(&event))
    {
      m_listEvents.push_back(event);
    }
  }

  //---------------------------------------------------------------------------
  void LowLevelInputGLFW::EndInputUpdate()
  {
    m_listEvents.clear();
  }

  //---------------------------------------------------------------------------
  IKeyboard* LowLevelInputGLFW::CreateKeyboard()
  {
    // Not implemented
    return NULL;
  }
}
