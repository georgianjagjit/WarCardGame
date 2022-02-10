#include "../../include/CardModel.h"
#include "../../include/GameController.h"
#include "../../include/GameUI.h"
#include "../../include/PlayerModel.h"

int main() {
  GameUI* gui = new GameUI();
  GameController gameCtrl(gui);
  PlayerModelInterface* p1 = new PlayerModel;
  PlayerModelInterface* Computer = new PlayerModel;

  gameCtrl.initializeGame(p1, Computer);

  delete p1;
  delete Computer;


  return 0;
}
