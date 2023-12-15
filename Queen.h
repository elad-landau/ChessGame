#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Board.h"

class Board;

class Queen : public Piece
{
public:

	Queen(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};

bool rookMove(Board* board, int sorcLet, int sorcNum, int destLet, int destNum);
bool bishopMove(Board* board, int sorcLet, int sorcNum, int destLet, int destNum);

#endif