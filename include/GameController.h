#ifndef INCLUDE_GAMECONTROLLER_H_
#define INCLUDE_GAMECONTROLLER_H_
#include <vector>
#include <string>
#include "../include/GameUI.h"
#include "../include/PlayerModel.h"
#include "../include/CardModel.h"

class GameController {
 public:
  PlayerModelInterface* player1 = nullptr;
  PlayerModelInterface* cpu = nullptr;
  std::vector<CardModel*> deck;
  std::vector<CardModel*> player1Table;
  std::vector<CardModel*> cpuTable;

  explicit GameController(GameUI* gui);

  ~GameController();
  void initializeGame(PlayerModelInterface*, PlayerModelInterface*);
  void createDeck();
  void dummyCreateDeck(CardModel * newCard);
  void splitDeck(std::vector<CardModel*> d);
  void gameLoop();
  void cardPickup(PlayerModelInterface* p);
  void cardCompare(std::vector<CardModel*> player1Table,
  std::vector<CardModel*> cpuTable);
  int validateString(std::string dirtyString);
  void playCard(PlayerModelInterface* p);
  void cardCompareWar();

 private:
  GameUI* gui;
};

#endif
