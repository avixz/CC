//---------------------------------------------------------------------------
// LowLevelInputGLFW.h
//---------------------------------------------------------------------------

#pragma once

#include <list>
#include "input/ILowLevelInput.h"

struct GLEQevent;

namespace CC
{
  class LowLevelGraphicsGLFW;
  class IKeyboard;

  /** LowLevelInputGLFW
   */
  class LowLevelInputGLFW : public ILowLevelInput
  {
    public:
      LowLevelInputGLFW(LowLevelGraphicsGLFW* lowLevelGraphics);
      ~LowLevelInputGLFW();

      void BeginInputUpdate();
      void EndInputUpdate();
      IKeyboard* CreateKeyboard();

    public:
      std::list<GLEQevent> m_listEvents;

    private:
      ILowLevelGraphics* m_lowLevelGraphics;
  };
}
