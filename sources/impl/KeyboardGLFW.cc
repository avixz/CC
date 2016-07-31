//---------------------------------------------------------------------------
// KeyboardGLFW.cpp
//---------------------------------------------------------------------------

#include "GLFW/glfw3.h"
#define GLEQ_IMPLEMENTATION
#include "gleq.h"
#include "impl/LowLevelInputGLFW.h"
#include "impl/KeyboardGLFW.h"

namespace CC
{
  //-------------------------------------------------------------------------
  KeyboardGLFW::KeyboardGLFW(LowLevelInputGLFW* lowLeveInputGLFW) :
    m_lowLevelInputGLFW(lowLeveInputGLFW)
  {
  }

  //-------------------------------------------------------------------------
  void KeyboardGLFW::Update()
  {
    m_listKeysPressed.clear();

    for(std::list<GLEQevent>::iterator it = m_lowLevelInputGLFW->
        m_listEvents.begin(); it != m_lowLevelInputGLFW->m_listEvents.end();
        ++it)
    {
      GLEQevent* event = &(*it);

      if(event->type != GLEQ_KEY_PRESSED && event->type != GLEQ_KEY_RELEASED)
      {
        continue;
      }
      //TODO: Capture the key info
      m_listKeysPressed.push_back(KeyPress(ccKey()));
    }
  }

  //-------------------------------------------------------------------------
  bool KeyboardGLFW::KeyIsPressed()
  {
    return m_listKeysPressed.empty() == false;
  }
}
