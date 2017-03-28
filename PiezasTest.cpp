/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, checkReset)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(0);
	actual = piezas.dropPiece(1);
	piezas.reset();
	actual = piezas.pieceAt(0,1);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, checkBlank)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	actual = piezas.pieceAt(0,3);
	ASSERT_EQ(actual, Blank);
}

TEST(PiezasTest, checkDropPieceX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	actual = piezas.pieceAt(0,0);
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkInvalidNegRow)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	actual = piezas.pieceAt(-1,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkInvalidOverRow)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	actual = piezas.pieceAt(3,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkInvalidNegCol)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	actual = piezas.pieceAt(0,-1);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkInvalidOverCol)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	actual = piezas.pieceAt(0,4);
	ASSERT_EQ(actual, Invalid);
}
	
TEST(PiezasTest, checkDropPieceO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(2);
	actual = piezas.dropPiece(3);
	actual = piezas.pieceAt(0,3);
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, checkDropPieceInvalidNegRowX)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(0);
	actual = piezas.pieceAt(-1,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidOverRowX)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(0);
	actual = piezas.pieceAt(3,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidNegColX)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.pieceAt(0,-1);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidOverColX)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.pieceAt(0,4);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidNegRowO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.dropPiece(3);
	actual = piezas.pieceAt(-1,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidOverRowO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.dropPiece(2);
	actual = piezas.pieceAt(3,0);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidNegColO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.dropPiece(0);
	actual = piezas.pieceAt(0,-1);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkDropPieceInvalidOverColO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.dropPiece(2);
	actual = piezas.pieceAt(0,4);
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkPieceAtX)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(1);
	actual = piezas.dropPiece(3);
	actual = piezas.pieceAt(0,1);
	ASSERT_EQ(actual, X);
}


TEST(PiezasTest, checkPieceAtO)
{
	Piezas piezas;
	Piece actual;
	actual = piezas.dropPiece(2);
	actual = piezas.dropPiece(3);
	actual = piezas.pieceAt(0,3);
	ASSERT_EQ(actual, O);
}

TEST(PiezasTest, checkWinRowZeroX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(-1);
	piezas.dropPiece(2);
	piezas.dropPiece(1);		
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
		
}

TEST(PiezasTest, checkWinRowOneX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkWinRowTwoX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(-1);
	piezas.dropPiece(1);
	piezas.dropPiece(-1);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(3);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}


TEST(PiezasTest, checkWinColZeroX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkWinColOneX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkWinColTwoX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkWinColThreeX)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	actual = piezas.gameState();
	ASSERT_EQ(actual, X);
}

TEST(PiezasTest, checkWinRowZeroO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(-1);
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(3);		
	piezas.dropPiece(1);
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinRowOneO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(2);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinRowTwoO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(2);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinColZeroO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(1);
	piezas.dropPiece(-1);
	piezas.dropPiece(2);
	piezas.dropPiece(2);
	piezas.dropPiece(3);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinColOneO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(2);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinColTwoO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(3);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinColThreeO)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(-1);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(2);
	piezas.dropPiece(-1);
	piezas.dropPiece(0);
	piezas.dropPiece(-1);
	piezas.dropPiece(2);
	piezas.dropPiece(2);		
	actual = piezas.gameState();
	ASSERT_EQ(actual, O);
		
}

TEST(PiezasTest, checkWinInvalid)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	actual = piezas.gameState();
	ASSERT_EQ(actual, Invalid);
}

TEST(PiezasTest, checkNoWin)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	actual = piezas.gameState();
	ASSERT_EQ(actual, Blank);

}

TEST(PiezasTest, checkNoWinTie)
{
	Piezas piezas;
	Piece actual;
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	actual = piezas.gameState();
	ASSERT_EQ(actual, Blank);

}

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
