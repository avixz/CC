//---------------------------------------------------------------------------
// GameSetupFactory.cc
//---------------------------------------------------------------------------

#include <iostream>
#include "game/GameSetupFactory.h"
#include "game/ILowLevelGameSetup.h"
#include "impl/LowLevelGameSetupLinux.h"

namespace CC
{
  //-----------------------------------------------------------------------
  GameSetupFactory::GameSetupFactory()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }

  //-----------------------------------------------------------------------
  ILowLevelGameSetup* GameSetupFactory::CreateGameSetup()
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#ifdef LINUX
    return new LowLevelGameSetupLinux();
#elif EMSC
    return new LowLevelGameSetupEmsc();
#endif
  }
}
