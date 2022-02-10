#ifndef CARDMODEL_H
#define CARDMODEL_H

class CardModelInterface {
 public:
  virtual ~CardModelInterface() {}

  virtual void setRank(int r) = 0;
  virtual void setSuit(char s) = 0;
  virtual int getRank() = 0;
  virtual char getSuit() = 0;
};

class CardModel : public CardModelInterface{
 public:
  CardModel();
  CardModel(int r, char s);
  virtual ~CardModel();
  void setRank(int r);
  void setSuit(char s);
  int getRank();
  char getSuit();
  bool operator==(const CardModel& c1) const {
    if (rank == c1.rank && suit == c1.suit)
      return true;
    return false;
  }
 private:
  int rank;
  char suit;
};
#endif
