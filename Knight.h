#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include "Board.h"

class Board;

class Knight : public Piece
{
public:

	Knight(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};
#endif