#include <vector>
#include "PlayerModel.h"
#include "CardModel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Exceptions.h"

/************************************************************
* Testing PlayerModel setName to see if it can handle NULL pointers
*************************************************************/
TEST(testPlayerModel, setName) {
  PlayerModel testPlayer1;
  //checking if the method can handle null pointers
  EXPECT_THROW(testPlayer1.setName(NULL), illegalArgumentException);
  //a valid string
  EXPECT_NO_THROW(testPlayer1.setName("George"));
}

/************************************************************
* Testing PlayerModel constructor, setName and getName methods
*************************************************************/
TEST(testPlayerModel, nameMethods) {
  PlayerModel testPlayer1;
  PlayerModel testPlayer2;

  testPlayer1.setName("George");
  testPlayer2.setName("Singh");

  EXPECT_EQ(testPlayer1.getName(), "George");
  EXPECT_EQ(testPlayer2.getName(), "Singh");
}

/************************************************************
* Testing PlayerModel constructor, addToStock, printStock
* ,getStockSize, removeFromStock
*************************************************************/
TEST(testPlayerModel, stockMethods) {
  PlayerModel testPlayer1;
  //CardModel CardModel

  CardModel* c1 = new CardModel (1, 'S');
  CardModel* c2 = new CardModel (2, 'C');
  CardModel* c3 = new CardModel (3, 'H');

  testPlayer1.addToStock(c1);
  testPlayer1.addToStock(c2);
  testPlayer1.addToStock(c3);

  EXPECT_EQ(testPlayer1.getStockSize(), 3);
  EXPECT_EQ(testPlayer1.removeFromStock(), c3);
  EXPECT_EQ(testPlayer1.removeFromStock(), c2);
  EXPECT_EQ(testPlayer1.getStockSize(), 1);
  //////// PRINTSTOCK needs to be tested still ////////
  delete c1;
  delete c2;
  delete c3;
}

/************************************************************
* Testing PlayerModel constructor, addToHand, removeFromHand
* ,getHandSize, getHand
*************************************************************/
TEST(testPlayerModel, handMethods) {
  PlayerModel testPlayer1;

  CardModel* c1 = new CardModel (1, 'S');
  CardModel* c2 = new CardModel (2, 'C');
  CardModel* c3 = new CardModel (3, 'H');
  std::vector<CardModel*> tempHand;

  testPlayer1.addToHand(c1);
  testPlayer1.addToHand(c2);
  testPlayer1.addToHand(c3);

  tempHand.push_back(c1);
  tempHand.push_back(c2);
  tempHand.push_back(c3);

  EXPECT_EQ(testPlayer1.getHandSize(), 3);
  EXPECT_EQ(testPlayer1.getHand(), tempHand);
  EXPECT_EQ(testPlayer1.removeFromHand(2), c3);
  EXPECT_NE(testPlayer1.getHand(), tempHand);
  EXPECT_EQ(testPlayer1.getHandSize(), 2);
  EXPECT_EQ(testPlayer1.removeFromHand(1), c2);
  EXPECT_EQ(testPlayer1.getHandSize(), 1);
  delete c1;
  delete c2;
  delete c3;
}
