#include "Piezas.h"
#include <iostream>
#include <vector>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	int rowMax = 3;
	board.resize(3);
	for(int row = 0; row < rowMax; row++)
	{
		board[row].resize(4);
	}
	reset();
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	int rowMax = 3;
	int colMax = 4;
	for(int row = 0; row < rowMax; row++)
	{
		for(int col = 0; col < colMax; col++)
		{
			board[row][col] = Blank;
		}
	}
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
	int colMax = 4;
	int rowMax = 3;
	if(column >= colMax || column < 0)
	{
		if(turn == X)
			turn = O;
		else
			turn = X;
		return Invalid;
	}
	if(pieceAt(2, column) != Blank)
	{
		if(turn == X)
			turn = O;
		else
			turn = X;
		return Blank;
	}
	Piece value = turn;
	for(int row = 0; row < rowMax; row++)
	{
		if(board[row][column] == Blank)
		{
			board[row][column] = turn;
			if(turn == X)
				turn = O;
			else
				turn = X;
			return value;
		}
	}
}


/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	int rowMax = 3;
	int colMax = 4;
	if((row >= rowMax || row <0) || (column >= colMax || column < 0))
		return Invalid;
	return board[row][column];
}
		

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
	int rowMax = 3;
	int colMax = 4;
	int xCount = 1;
	int oCount = 1;
	int xMaxRow = 0;
	int oMaxRow = 0;
	int xMaxCol = 0;
	int oMaxCol = 0;
	for(int row = 0; row < rowMax; row++)
	{
		for(int col = 0; col <= colMax; col++)
		{
			if(board[row][col] == Blank)
				return Invalid;
		}
	}
	for(int row = 0; row < rowMax; row++)
	{
		for(int col = 0; col < colMax-1; col++)
		{
			if(board[row][col] == board[row][col+1])
			{
				if(board[row][col] == X)
					xCount++;
				else
					oCount++;
			}
		}
		if(xCount > xMaxRow)
			xMaxRow = xCount;
		if(oCount > oMaxRow)
			oMaxRow = oCount;
		xCount = 1;
		oCount = 1;	
	}
	for(int col = 0; col < colMax; col++)
	{
		for(int row = 0; row < rowMax-1; row++)
		{
			if(board[row][col] == board[row+1][col])
			{
				if(board[row][col] == X)
					xCount++;
				else
					oCount++;
			}
		}
		if(xCount > xMaxCol)
			xMaxCol = xCount;
		if(oCount > oMaxCol)
			oMaxCol = oCount;
		xCount = 1;
		oCount = 1;	
	}
	if(xMaxCol > xMaxRow)
		xMaxRow = xMaxCol;
	if(oMaxCol > oMaxRow)
		oMaxRow = oMaxCol;
	if(xMaxRow > oMaxRow)	
		return X;
	if(oMaxRow > xMaxRow)
		return O;
	return Blank;
}		
