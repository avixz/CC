//---------------------------------------------------------------------------
// Input.cc
//---------------------------------------------------------------------------

#include "input/ILowLevelInput.h"
#include "input/IInputDevice.h"
#include "input/IKeyboard.h"
#include "input/Input.h"

namespace CC
{
  //---------------------------------------------------------------------------
  Input::Input(ILowLevelInput* lowLevelInput) :
    m_lowLevelInput(lowLevelInput)
  {
    m_keyboard = m_lowLevelInput->CreateKeyboard();
    m_listInputDevices.push_back(m_keyboard);
  }

  //---------------------------------------------------------------------------
  void Input::Update(float timeStep)
  {
    m_lowLevelInput->BeginInputUpdate();

    for(InputDeviceListIterator it = m_listInputDevices.begin();
        it != m_listInputDevices.end(); ++it)
    {
      (*it)->Update();
    }

    m_lowLevelInput->EndInputUpdate();
  }
}
