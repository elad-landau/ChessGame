#include "King.h"


// a constructor for the Piece King
King::King(bool color) : Piece(color){}


/*
The function checks if the move the player did with the king, is valid.
*/
bool King::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	Board* board = static_cast<Board*>(bor);

	if ((destNum == sorcNum + 1) && (destLet == sorcLet + 1)){
		return true;
	}
	if ((destNum == sorcNum + 1) && (destLet == sorcLet)){
		return true;
	}
	if ((destNum == sorcNum + 1) && (destLet == sorcLet - 1)){
		return true;
	}
	if ((destNum == sorcNum) && (destLet == sorcLet - 1)){
		return true;
	}
	if ((destNum == sorcNum - 1) && (destLet == sorcLet - 1)){
		return true;
	}
	if ((destNum == sorcNum - 1) && (destLet == sorcLet)){
		return true;
	}
	if ((destNum == sorcNum - 1) && (destLet == sorcLet + 1)){
		return true;
	}
	if ((destNum == sorcNum) && (destLet == sorcLet + 1)){
		return true;
	}
	return false;

}
