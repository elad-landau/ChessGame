#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Board.h"

class Board;

class Rook : public Piece
{
public:

	Rook(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};
#endif