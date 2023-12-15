#include "Pawn.h"

// a constructor for the piece Pawn
Pawn::Pawn(bool color) :Piece(color){}

/*
The function checks if the move the player did with the Pawn, is valid.
*/
bool Pawn::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	Board* board = static_cast<Board*>(bor);
	if ((sorcNum == 1) && (destNum == sorcNum + 2) && (destLet == sorcLet) && (board->checkIfClear(destLet, destNum)))
		return true;
	if ((sorcNum == 6) && (destNum == sorcNum - 2) && (destLet == sorcLet) && (board->checkIfClear(destLet, destNum)))
		return true;
	if (!getColor() && (destLet == sorcLet) && (destNum == sorcNum + 1) && (board->checkIfClear(destLet, destNum)))
		return true;
	if (getColor() && (destLet == sorcLet) && (destNum == sorcNum - 1) && (board->checkIfClear(destLet, destNum)))
		return true;
	if (!getColor() && !(board->checkIfClear(destLet, destNum)) && (destNum == sorcNum + 1)){
		if ((destLet == sorcLet - 1) || (destLet == sorcLet + 1))
			return true;
	}
	if (getColor() && !(board->checkIfClear(destLet, destNum)) && (destNum == sorcNum - 1)){
		if ((destLet == sorcLet - 1) || (destLet == sorcLet + 1))
			return true;
	}
	return false;
}