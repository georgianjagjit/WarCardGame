#ifndef GAMEUI_H
#define GAMEUI_H
#include <iostream>
#include <string>
#include <vector>
#include "PlayerModel.h"
#include "CardModel.h"

class GameUI {
 public:
     GameUI();
     ~GameUI();
     virtual std::string nameInputMenu();
     virtual void printPlayerHand(PlayerModelInterface* p);
     virtual void printPlayerStockSize(PlayerModelInterface* p);
     virtual void printWinner(PlayerModelInterface* p, PlayerModelInterface* c);
     virtual void printCard(CardModel* card);
     virtual std::string chooseCard();
     virtual void printPlayedCards(std::vector<CardModel*> player1Table,
    std::vector<CardModel*> cpuTable);
    virtual void printWarCondition();
    virtual void printWarConditionFail();
    virtual void helpMenu();
 private:
};

#endif  // INCLUDE_GAMEUI_H_
