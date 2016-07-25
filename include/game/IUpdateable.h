//---------------------------------------------------------------------------
// IUpdateable.h
//---------------------------------------------------------------------------

#pragma once

namespace CC
{
  /** IUpdateable
   */
  class IUpdateable
  {
    public:
      virtual void Update(float timeStep){}
  };
}
