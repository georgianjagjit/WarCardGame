#include <string>
#include <vector>
#include "CardModel.h"
#include "GameController.h"
#include "GameUI.h"
#include "PlayerModel.h"

PlayerModel::PlayerModel() {}

PlayerModel::~PlayerModel() {}

/**
* Sets the players name
*
* @param std::string n - name of the player
**/
void PlayerModel::setName(std::string n) {
  playerName = n;
}

/**
* returns players name
*
* @return std::string playerName - name of the player
**/
std::string PlayerModel::getName() {
  return playerName;
}

/**
* Adds a card to players stockpile
*
* @param CardModel card* - the card to be added to players stock
* @return void
**/
void PlayerModel::addToStock(CardModel* card) {
  playerStock.push_back(card);
}

/**
* Prints out the players stockpile
*
* @return void
**/
void PlayerModel::printStock() {
  int i = 0;
    for (auto it = playerStock.begin(); it != playerStock.end(); ++it) {
      std::cout << " " << std::endl;
      std::cout << "playerStock: "
      << playerStock[i]->getRank() << playerStock[i]->getSuit();
      ++i;
    }
}

/**
* returns size of stockpile
*
* @return int playerStock.size() - the size of the stockpile (vector) of cards
**/
int PlayerModel::getStockSize() {
  return playerStock.size();
}

/**
* returns size of players hand
*
* @return int playerHand.size() - The size of the hand (vector) of cards
**/
int PlayerModel::getHandSize() {
  return playerHand.size();
}

/**
* returns vector of players cards
*
* @return std::vector playerHand - a copy of the players hand
**/
std::vector<CardModel*> PlayerModel::getHand() {
  return playerHand;
}

/**
* Adds card to players hand
*
* @param CardModel c - card to be added to players hand
* @return void
**/
void PlayerModel::addToHand(CardModel* card) {
  playerHand.push_back(card);
}

/**
* Removes card from players hand and returns the same card
*
* @return CardModel tempCard
**/
CardModel* PlayerModel::removeFromHand(int i) {
  CardModel* tempCard;
  tempCard = playerHand.at(i);
  playerHand.erase(playerHand.begin()+i);
  return tempCard;
}

/**
* Removes card from stockpile and returns the same card
*
* @return CardModel - A card removed from players stock
**/
CardModel* PlayerModel::removeFromStock() {
  CardModel* tempCard;
  tempCard = playerStock.back();
  playerStock.pop_back();
  return tempCard;
}
