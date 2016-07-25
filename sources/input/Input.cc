//---------------------------------------------------------------------------
// Input.cc
//---------------------------------------------------------------------------

#include "input/ILowLevelInput.h"
#include "input/IInputDevice.h"
#include "input/Input.h"

namespace CC
{
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
