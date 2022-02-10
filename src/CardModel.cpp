#include "CardModel.h"
#include "GameController.h"
#include "GameUI.h"
#include "PlayerModel.h"

CardModel::CardModel() {}

CardModel::CardModel(int r, char s) {
  rank = r;
  suit = s;
}

CardModel::~CardModel() {}

/**
* Rank setter for Card objects
*
* @param std::string rank
**/
void CardModel::setRank(int r) {
  rank = r;
}

/**
* Suite setter for Card objects
*
* @param std::string suite
**/
void CardModel::setSuit(char s) {
  suit = s;
}

/**
* Rank getter for Card objects
*
* @return std::string rank
**/
int CardModel::getRank() {
  return rank;
}

/**Forked from Course3720 / Fall 2021 / War
* Rank getter for Card objects
*
* @return char rank
**/
char CardModel::getSuit() {
  return suit;
}
