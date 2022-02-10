#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <cstdlib>
#include <ctime>
#include "GameController.h"
#include "CardModel.h"

/*
* GameController constructor
* @param GameUI* gui - The view class.
* @return void
*/
GameController::GameController(GameUI* InputGui) {
  gui = InputGui;
}

/*
* Default Deconstructor
*/
GameController::~GameController() {}

/*
* Initializes player objects, calls functions required for game setup
* @return void
*/
void GameController::initializeGame(PlayerModelInterface* p1,
  PlayerModelInterface* Computer) {
    //CardModel ob;
    player1 = p1;
    cpu = Computer;
    std::string playerName = gui->nameInputMenu();
    player1->setName(playerName);
    cpu->setName("CPU");
    createDeck();
    splitDeck(deck);
    gameLoop();
}

/*
* The main game loop, runs until one player has an empty stock pile.
* @return void
*/
void GameController::gameLoop() {
  while (player1->getStockSize() > 0 && cpu->getStockSize() > 0) {
    player1Table.clear();
    cpuTable.clear();
    cardPickup(player1);
    cardPickup(cpu);
    gui->printPlayerHand(player1);
    playCard(player1);
    playCard(cpu);
    gui->printPlayedCards(player1Table, cpuTable);

    gui->printPlayerStockSize(player1);
    gui->printPlayerStockSize(cpu);
    std::cout << "----------------------------------------------------" << "\n";

    std::cout << "\n" << "Card Compare here: " << "\n";
    cardCompare(player1Table, cpuTable);
    gui->printPlayerStockSize(player1);
    gui->printPlayerStockSize(cpu);
    std::cout << "----------------------------------------------------" << "\n";
  }
  gui->printWinner(player1, cpu);
}

/*
* Allows a player to choose a card from their hand to play to the table.
* Removes card from the players hand, adds to either player1Table or cpuTable
*
* @param PlayerModel* p - the player object to play the cards
* @return void
*/
void GameController::playCard(PlayerModelInterface* p) {
  int cardChoice = 0;
  bool validChoice = false;
  CardModel* tempCard = new CardModel;

  if (p->getName().compare("CPU") == 0) {
    unsigned int seed = time(NULL);
    cardChoice = (rand_r(&seed) % 3) + 1;
    tempCard = p->removeFromHand(cardChoice-1);
    cpuTable.push_back(tempCard);
    validChoice = true;
  }

  while (!validChoice) {
    cardChoice = validateString(gui->chooseCard());
    if (cardChoice == 1 || cardChoice == 2 || cardChoice == 3) {
      tempCard = p->removeFromHand(cardChoice-1);
      player1Table.push_back(tempCard);
      validChoice = true;
    }
    if (cardChoice == 0) {
      gui->helpMenu();
    }
  }
}


/**
*  Creates a decks worth of card objects, then
*  populates the std::vector<CardModel> deck object with them.
*
* @return void
**/
void GameController::createDeck() {
  for (int i = 0; i <= 3; i++) {
      CardModel* newCard = new CardModel();

      if (i == 0) {
        newCard->setSuit('C');
      } else if (i == 1) {
        newCard->setSuit('S');
      } else if (i == 2) {
        newCard->setSuit('H');
      } else {
        newCard->setSuit('D');
      }

      for (int k = 2; k <= 14; k++) {
          newCard->setRank(k);
          deck.push_back(newCard);
        }
      }
  std::random_shuffle(deck.begin(), deck.end());
}

void GameController::dummyCreateDeck(CardModel * newCard) {
  for (int i = 0; i <= 3; i++) {
      newCard = new CardModel;
      if (i == 0) {
        newCard->setSuit('C');
      } else if (i == 1) {
        newCard->setSuit('S');
      } else if (i == 2) {
        newCard->setSuit('H');
      } else {
        newCard->setSuit('D');
      }

      for (int k = 2; k <= 14; k++) {
          newCard->setRank(k);
          deck.push_back(newCard);
        }
      }
  std::random_shuffle(deck.begin(), deck.end());
}


/**
* Splits deck into each players stock pile
*
* @param std::vector<CardModel> d - vector of a full card deck.
* @return void
**/
void GameController::splitDeck(std::vector<CardModel*> d) {
  for (int k = 0; k <= 51; k++) {
    if (k <= 25) {
      player1->addToStock(deck[k]);
    } else {
      cpu->addToStock(deck[k]);
    }
  }
}

/**
* Takes cards from stockpile till hand has 3 cards
*
* @param PlayerModel* p - the Player object in which picks up cards
* @return void
**/
void GameController::cardPickup(PlayerModelInterface* p) {
        while (p->getHandSize() < 3) {
          CardModel* tempCard;
          tempCard = p->removeFromStock();
          p->addToHand(tempCard);
      }
}

/**
* Takes cards from stockpile till hand has 3 cards
*
* @param std::vector<CardModel> player1Table - player 1s played cards
* @param std::vector<CardModel> cpuTable - cpu's played cards
* @return void
**/
void GameController::cardCompare(std::vector<CardModel*> player1Table,
  std::vector<CardModel*> cpuTable) {
  gui->printPlayedCards(player1Table, cpuTable);
  if (player1Table.at(0)->getRank() > cpuTable.at(0)->getRank()) {
    player1->addToStock(player1Table.at(0));
    player1->addToStock(cpuTable.at(0));
    std::cout << "\n" << player1->getName() << " won that round.";
  } else if (player1Table.at(0)->getRank() < cpuTable.at(0)->getRank()) {
    cpu->addToStock(player1Table.at(0));
    cpu->addToStock(cpuTable.at(0));
    std::cout << "\n" << cpu->getName() << " won that round.";
  } else {
    cardCompareWar();
  }
}

/**
* Gets called when a war condition happens (two players play matching cards)
* Adds three cards from each player to table, compares for higher value, then
* adds them to the winning players stockpile.
*
* @return void
* @exception std::out_of_range& e - if a player has >3 cards in stockpile
**/
void GameController::cardCompareWar() {
  gui->printWarCondition();
  try {
    for (int i = 0; i < 3; i++) {
    player1Table.push_back(player1->removeFromStock());
    cpuTable.push_back(cpu->removeFromStock());
  }
  }
  catch (const std::out_of_range& e) {
    std::cout << "A player has ran out of cards fulfilling the war." << "\n";
  }
  gui->printPlayedCards(player1Table, cpuTable);

  bool isWinner = false;
  for (int i = 0; i < 3; i++) {
    if (player1Table.at(i)->getRank() > cpuTable.at(i)->getRank()) {
      for (int k = 0; k < 4; k++) {
        player1->addToStock(player1Table.at(k));
        player1->addToStock(cpuTable.at(k));
      }
      isWinner = true;
      break;
    } else if (cpuTable.at(i)->getRank() > player1Table.at(i)->getRank()) {
      for (int j = 0; j < 4; j++) {
        player1->addToStock(player1Table.at(j));
        player1->addToStock(cpuTable.at(j));
      }
      isWinner = true;
      break;
    }
  }
  if (!isWinner) {
    gui->printWarConditionFail();
  }
}

/*
* Validates string input, with only valid input being 0, 1, 2, or 3
*
* @param std::string dirtyString - unfiltered input from user
* @return int - an int from 0-3
*/
int GameController::validateString(std::string dirtyString) {
  bool valid = false;
  while (!valid) {
    try {
    int choice = std::stoi(dirtyString);
    if (choice == 1 || choice == 2 || choice == 3 || choice == 0) {
      valid = true;
      return choice;
    } else {
      std::cout << "\n" << "INVALID INPUT, ENTER DIGIT 0-3" << "\n";
      return 4;
      }
    } catch (std::invalid_argument) {
      std::cout << "\n" << "INVALID INPUT, ENTER DIGIT 0-3" << "\n";
      return 4;
    }
  }
  return 4;
}
