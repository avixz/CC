//---------------------------------------------------------------------------
// GameSetupFactory.cc
//---------------------------------------------------------------------------

#include "game/GameSetupFactory.h"
#include "game/ILowLevelGameSetup.h"
#include "impl/LowLevelGameSetupLinux.h"

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
    return new LowLevelGameSetupLinux();
#elif EMSC
    return new LowLevelGameSetupEmsc();
#endif
  }
}
