//---------------------------------------------------------------------------
// Input.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include "game/IUpdateable.h"

namespace CC
{
  class IKeyboard;
  class ILowLevelInput;
  class IInputDevice;

  typedef std::list<IInputDevice*> InputDeviceListType;
  typedef std::list<IInputDevice*>::iterator InputDeviceListIterator;

  /** Input
   */
  class Input : public IUpdateable
  {
    public:

      /** Updates the input, called by Game
       */
      void Update(float timeStep);

    private:
      ILowLevelInput* m_lowLevelInput;
      InputDeviceListType m_listInputDevices;
  };
}
