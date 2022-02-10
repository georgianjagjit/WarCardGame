#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H
#include <string>
#include <vector>
#include "CardModel.h"

class PlayerModelInterface {
 public:
  virtual ~PlayerModelInterface() {}

  virtual void setName(std::string n) = 0;
  virtual std::string getName() = 0;

  virtual void addToStock(CardModel*) = 0;
  virtual void printStock() = 0;
  virtual int getStockSize() = 0;
  virtual CardModel* removeFromStock() = 0;

  virtual int getHandSize() = 0;
  virtual std::vector<CardModel*> getHand() = 0;
  virtual void addToHand(CardModel* x) = 0;
  virtual CardModel* removeFromHand(int i) = 0;
};

class PlayerModel : public PlayerModelInterface {
 public:
  PlayerModel();
  virtual ~PlayerModel();

  virtual void setName(std::string n);
  virtual std::string getName();
  virtual void addToStock(CardModel*);
  virtual void printStock();
  virtual int getStockSize();
  virtual int getHandSize();

  std::vector<CardModel*> getHand();
  virtual CardModel* removeFromStock();
  virtual void addToHand(CardModel* x);
  virtual CardModel* removeFromHand(int i);

 private:
  std::vector<CardModel*> playerStock;
  std::vector<CardModel*> playerHand;
  std::string playerName;
};
#endif  // INCLUDE_PLAYERMODEL_H_
