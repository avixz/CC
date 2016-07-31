//---------------------------------------------------------------------------
// KeyboardGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include "input/InputTypes.h"
#include "input/IKeyboard.h"

namespace CC
{
  class LowLevelInputGLFW;

  class KeyboardGLFW : public IKeyboard
  {
    public:
      KeyboardGLFW(LowLevelInputGLFW* lowLevelInputGLFW);

      void Update();
      bool KeyIsPressed();

    private:
      std::list<KeyPress> m_listKeysPressed;
      LowLevelInputGLFW* m_lowLevelInputGLFW;
  };
}
