#include "Knight.h"

// a constructor for the Piece knight
Knight::Knight(bool color) : Piece(color){}


/*
The function checks if the move the player did with the knight, is valid.
*/
bool Knight::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	Board* board = static_cast<Board*>(bor);
	if ((destNum == sorcNum + 2) && (destLet == sorcLet + 1)){
		return true;
	}
	if ((destNum == sorcNum + 2) && (destLet == sorcLet - 1)){
		return true;
	}
	if ((destNum == sorcNum + 1) && (destLet == sorcLet - 2)){
		return true;
	}
	if ((destNum == sorcNum - 1) && (destLet == sorcLet - 2)){
		return true;
	}
	if ((destNum == sorcNum - 2) && (destLet == sorcLet - 1)){
		return true;
	}
	if ((destNum == sorcNum - 2) && (destLet == sorcLet + 1)){
		return true;
	}
	if ((destNum == sorcNum - 1) && (destLet == sorcLet + 2)){
		return true;
	}
	if ((destNum == sorcNum + 1) && (destLet == sorcLet + 2)){
		return true;
	}
	return false;
}