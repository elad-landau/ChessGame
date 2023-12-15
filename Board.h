#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class Rook;
class Bishop;
class King;
class Knight;
class Pawn;
class Queen;
class Piece;

using namespace std;

static bool turn = true;

class Board{

public:
	Board();
	~Board();
	char* checkMove(string move);
	int checkIfChess(int destLet, int destNum, int sorcLet, int sorcNum);
	void eatTool(int sorcRow, int sorcLine, int destRow, int destLine);
	bool checkIfClear(int line, int row);

private:
	Piece* _board[8][8];

};
#endif