#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Board.h"

class Board;

class Bishop : public Piece
{
public:

	Bishop(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};
#endif