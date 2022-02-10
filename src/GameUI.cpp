#include <iostream>
#include <string>
#include <vector>
#include "GameUI.h"
#include "GameController.h"

/*
* Default Constructor
*/
GameUI::GameUI() {}

/*
* Default destructor
*/
GameUI::~GameUI() {}

/**
* The games welcome screen, allows a user to input name.
*
* @return std::string playerName - the players name
*/
std::string GameUI::nameInputMenu() {
  std::string playerName;
  std::cout << "Welcome to war!" << std::endl;
  helpMenu();
  std::cout << "Please enter your name: ";
  getline(std::cin, playerName);
  std::cout << std::endl;
  return playerName;
}

/**
* Prints the cards in the player objects hand
*
* @param PlayerModel* p - the player in which to print the hand
* @return void
*/
void GameUI::printPlayerHand(PlayerModelInterface* p) {
  std::cout<< "Your hand:";
  CardModel* tempCard = new CardModel(1, 'C');

  for (int i = 0; i < p->getHand().size(); i++) {
    std::cout << "\n" << "Card " <<  i+1 <<": ";
    tempCard = p->getHand().at(i);
    printCard(tempCard);
  }
  std::cout << "\n";
}

/**
* Prints out the card rank and suit
*
* @return void
*/
void GameUI::printCard(CardModel* card) {
  if (card->getRank() == 11) {
    std::cout << "Jack";
  } else if (card->getRank() == 12) {
    std::cout << "Queen";
  } else if (card->getRank() == 13) {
    std::cout << "King";
  } else if (card->getRank() == 14) {
    std::cout << "Ace";
  } else {
    std::cout << card->getRank();
  }

  if (card->getSuit() == 'C') {
    std::cout << " of Clubs";
  }
  if (card->getSuit() == 'S') {
    std::cout << " of Spades";
  } else if (card->getSuit() == 'H') {
    std::cout << " of Hearts";
  } else if (card->getSuit() == 'D') {
    std::cout << " of Diamonds";
  }
}

/**
* Prints out the size of the cards the player is holding
*
* @return void
*/
void GameUI::printPlayerStockSize(PlayerModelInterface* p) {
  std::cout << "\n" << "\n";
  std::cout << p->getName() << " has " << p->getStockSize() <<
    " cards remaining in their stock pile." << std::endl;
}

/**
* Prints out the winner of the game
*
* @return void
*/
void GameUI::printWinner(PlayerModelInterface* p, PlayerModelInterface* c) {
  char x;
  std::string winner;
  if (p->getStockSize() == 0) {
    winner = c->getName();
  } else if (c->getStockSize() == 0) {
    winner = p->getName();
  }
  std::cout << "\n";
  std::cout << "------------------------------------------" << "\n";
  std::cout << "     " << winner << " Has won the Game!!!" << "\n";
  std::cout << "------------------------------------------" << "\n";
  std::cout << "Enter any key to exit game." << "\n";
  std::cin >> x;
}

/**
* Gets input from the player, then returns it as a string.
*
* @return std::string i - the users input of which card to play.
**/
std::string GameUI::chooseCard() {
  std::cout << "Choose a card to play: 1, 2, or 3. Input 0 for help.";
  std::string i;
  getline(std::cin, i);
  return i;
}

/**
* Print out the played cards on the table for player and cpu
*
* @return void
*/
void GameUI::printPlayedCards(std::vector<CardModel*> player1Table,
  std::vector<CardModel*> cpuTable) {
  int k = 0;
  int i = 0;
  //CardModel tempCard;
  CardModel* tempCard = new CardModel(2, 'C');
  std::cout << " " << std::endl;
  std::cout << "Your played cards: ";
    for (auto it = player1Table.begin(); it != player1Table.end(); ++it)  {
    tempCard = player1Table.at(k);
    printCard(tempCard);
    std::cout << "\n";
    ++k;
  }
  std::cout << " " << std::endl;
  std::cout << "CPU's played cards: ";

  for (auto it = cpuTable.begin(); it != cpuTable.end(); ++it) {
    tempCard = cpuTable.at(i);
    printCard(tempCard);
    std::cout << "\n";
    ++i;
  }
}

/**
* Print out the War message when the condition is met
*
* @return void
*/
void GameUI::printWarCondition() {
  std::cout << "\n";
  std::cout << "------------------------------------------" << "\n";
  std::cout << " Both cards hold the same value! It's War!" << "\n";
  std::cout << " Both you and CPU add three cards to table!" << "\n";
  std::cout << "------------------------------------------" << "\n";
}

/**
* Print out the 2nd War message when both the first
* and the second war condition is met
*
* @return void
*/
void GameUI::printWarConditionFail() {
  std::cout << "------------------------------------------" << "\n";
  std::cout << " The near impossible event has occured in " << "\n";
  std::cout << " which all 4 cards hold identical ranks!" << "\n";
  std::cout << " These cards have been removed from play!" << "\n";
  std::cout << "------------------------------------------" << "\n";
}

/**
* Print out the help menu for the player
*
* @return void
*/
void GameUI::helpMenu() {
  std::cout << "------------------------------------------------------" << "\n";
  std::cout << "Rules: " << std::endl;
  std::cout << "This is a variation of the card game war where a deck of "
  "cards is split between the player(You) and a CPU and added to your "
  "stockpile. "
  "You will both draw a deck of 3 cards to choose from where the "
  "higher card wins and gets the opponents cards added to their stockpile. "
  "The player to run out of cards in their stockpile loses." << std::endl;
  std::cout << "------------------------------------------------------" << "\n";
  std::cout << "Enter the number of the card you wish to play." << "\n";
  std::cout << "Ex. for Card 1 enter 1" << "\n";
  std::cout << "------------------------------------------------------" << "\n";
}
