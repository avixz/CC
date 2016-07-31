//---------------------------------------------------------------------------
// InputTypes.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  enum ccKey
  {
    ccKey_ESCAPE,
    ccKey_RETURN,
    ccKey_LastEnum
  };

  struct KeyPress
  {
    KeyPress(ccKey key) :
      m_key(key)
    {
    }

    ccKey m_key;
  };
}
