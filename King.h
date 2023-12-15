#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Board.h"

class Board;

class King : public Piece
{
public:

	King(bool color);
	bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);

};
#endif