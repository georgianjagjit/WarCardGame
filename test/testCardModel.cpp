#include "CardModel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(testCardModel, constructorInjection) {
  CardModel testModel(1, 'D');
  CardModel testModel02(4, 'H');

  EXPECT_EQ(testModel.getRank(), 1);
  EXPECT_EQ(testModel.getSuit(), 'D');
  EXPECT_EQ(testModel02.getRank(), 4);
  EXPECT_EQ(testModel02.getSuit(), 'H');
}

TEST(testCardModel, setterInjection) {
  CardModel testModel;
  CardModel testModel02;
  testModel.setRank(2);
  testModel.setSuit('c');
  testModel02.setRank(5);
  testModel02.setSuit('s');

  EXPECT_EQ(testModel.getRank(), 2);
  EXPECT_EQ(testModel.getSuit(), 'c');
  EXPECT_EQ(testModel02.getRank(), 5);
  EXPECT_EQ(testModel02.getSuit(), 's');
} // test
