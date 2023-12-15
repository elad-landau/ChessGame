#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Board.h"

class Board;

class Pawn : public Piece
{
public:

	Pawn(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};
#endif