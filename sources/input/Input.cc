//---------------------------------------------------------------------------
// Input.cc
//---------------------------------------------------------------------------

#include "input/ILowLevelInput.h"
#include "input/IInputDevice.h"
#include "input/Input.h"

namespace CC
{
  //---------------------------------------------------------------------------
  Input::Input(ILowLevelInput* lowLevelInput) :
    m_lowLevelInput(lowLevelInput)
  {
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
