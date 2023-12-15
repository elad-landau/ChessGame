#include "Bishop.h"

// a constructor for the Piece Bishop
Bishop::Bishop(bool color) : Piece(color){}


/*
The function checks if the move the player did with the bishop, is valid.
*/
bool Bishop::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	// the pointer is void to make the function definition to stay the same, without including the board in class Board.

	Board* board = static_cast<Board*>(bor);

	if (destNum - sorcNum == destLet - sorcLet){
		for (int i = sorcNum; i < destNum; i++){
			if (!board->checkIfClear(destLet + i, sorcNum + i))
				return false;
		}
		return true;
	}
	if (destNum - sorcNum == destLet + sorcLet){
		for (int i = sorcNum; i < destNum; i++){
			if (!board->checkIfClear(destLet - i, sorcNum + i))
				return false;
		}
		return true;
	}
	if (destNum + sorcNum == destLet - sorcLet){
		for (int i = sorcNum; i < destNum; i++){
			if (!board->checkIfClear(destLet + i, sorcNum - i))
				return false;
		}
		return true;
	}
	if (destNum + sorcNum == destLet + sorcLet){
		if (destNum > sorcNum)
		{
			for (int i = sorcNum; i < destNum; i++){
				if (!board->checkIfClear(destLet - i, sorcNum - i))
					return false;
			}
			return true;
		}
		else
		{
			for (int i = destNum; i < sorcNum; i++){
				if (!board->checkIfClear(destLet - i, sorcNum - i))
					return false;
			}
			return true;
		}
	}
	return false;
}
