//---------------------------------------------------------------------------
// IKeyboard.h
//---------------------------------------------------------------------------

#pragma once

#include "input/IInputDevice.h"

namespace CC
{
  class IKeyboard : public IInputDevice
  {
    public:
      virtual bool KeyIsPressed() = 0;
  };
}
