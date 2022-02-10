#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CardModel.h"
#include "PlayerModel.h"
#include "GameUI.h"
#include "GameController.h"

using ::testing::Expectation;
using ::testing::Return;
using ::testing::_;

class MockCardModel : public CardModelInterface {
 public:
  explicit MockCardModel() {}
  virtual ~MockCardModel() {}

  MOCK_METHOD1(setRank, void(int));
  MOCK_METHOD1(setSuit, void(char));
  MOCK_METHOD0(getRank, int());
  MOCK_METHOD0(getSuit, char());
};

class MockPlayerModel : public PlayerModelInterface {
 public:
  explicit MockPlayerModel() {}
  virtual ~MockPlayerModel() {}

  MOCK_METHOD1(setName, void(std::string n));
  MOCK_METHOD0(getName, std::string());

  MOCK_METHOD1(addToStock, void(CardModel*));
  MOCK_METHOD0(getStockSize, int());
  MOCK_METHOD0(printStock, void());
  MOCK_METHOD0(removeFromStock, CardModel*());

  MOCK_METHOD0(getHandSize, int());
  MOCK_METHOD0(getHand, std::vector<CardModel*>());
  MOCK_METHOD1(addToHand, void(CardModel* x));
  MOCK_METHOD0(close, std::string());
  MOCK_METHOD1(removeFromHand, CardModel*(int i));
};

class GameUIStub : public GameUI {
  std::string nameInputMenu() {
    return "Jagjit";
  }

  std::string chooseCard() {
    return "2";
  }
};

TEST(testGameController, InitializeGametest) {
  GameUI* UI = new GameUIStub();
  MockPlayerModel mPlayer;
  MockPlayerModel mPlayer2;
  GameController testGame(UI);

  // testGame.initializeGame(Mock1, Mock2);
  Expectation e = EXPECT_CALL(mPlayer, setName("Jagjit"))
  .Times(1);

  Expectation s = EXPECT_CALL(mPlayer2, setName("CPU"))
  .Times(1);

  testGame.initializeGame(&mPlayer, &mPlayer2);
  //testGame.validateString("two");
  //EXPECT_EQ(testGame.validateString(), 2);
  delete UI;
}

TEST(testGameController, createDeckTest) {
  GameUI* UI = new GameUIStub();
  MockCardModel mockCard = MockCardModel();
  GameController testGame(UI);

  Expectation e = EXPECT_CALL(mockCard, setSuit(_))
  .Times(4);

  EXPECT_CALL(mockCard, setRank(_))
  .Times(12)
  .After(e);

  testGame.dummyCreateDeck(&mockCard);
  delete UI;
}

TEST(testGameController, splitDeckTest) {
  GameUI* UI = new GameUIStub();
  //GameController* GC = new GameController();
  MockCardModel mockCard;
  MockPlayerModel mockPlayer;
  MockPlayerModel mockPlayer2;
  GameController testGame(UI);

  //Expectation e = EXPECT_CALL(mockCard, splitDeck())
  //.Times(1);

  //Expectation s = EXPECT_CALL(mockPlayer2, addToStock(_))
  //.Times(1);

  //GC->initializeGame();
  testGame.initializeGame(&mockPlayer, &mockPlayer2);
  delete UI;
}
