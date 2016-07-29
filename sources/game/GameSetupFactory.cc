//---------------------------------------------------------------------------
// GameSetupFactory.cc
//---------------------------------------------------------------------------

#include "game/GameSetupFactory.h"
#include "game/ILowLevelGameSetup.h"

namespace CC
{
  //-----------------------------------------------------------------------
  GameSetupFactory::GameSetupFactory()
  {
  }

  //-----------------------------------------------------------------------
  ILowLevelGameSetup* GameSetupFactory::CreateGameSetup()
  {
#ifdef LINUX
    return new LinuxGameSetup();
#elif EMSC
    return new EmscGameSetup();
#endif
  }
}
