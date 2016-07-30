//---------------------------------------------------------------------------
// SystemTest.cc
//---------------------------------------------------------------------------

#include <unistd.h>
#include "CC.h"

using namespace CC;

int ccMain()
{
  // Create factories
  GameSetupFactory* setupFactory = new GameSetupFactory();

  // Init game
  ILowLevelGameSetup* gameSetup = setupFactory->CreateGameSetup();
  Game* game = new Game(gameSetup, 800, 600);
  sleep(5);
}
