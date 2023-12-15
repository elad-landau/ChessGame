#include "Queen.h"

// a constructor for the Piece Queen
Queen::Queen(bool color) : Piece(color){}

bool rookMove(Board* board, int sorcLet, int sorcNum, int destLet, int destNum)
{
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

bool bishopMove(Board* board, int sorcLet, int sorcNum, int destLet, int destNum)
{
	if (sorcLet != destLet && sorcNum != destNum)
		return false;
	if (sorcLet == destLet){
		if (sorcNum > destNum){
			for (int i = 1; i < sorcNum - destNum; i++){
				if (!board->checkIfClear(destLet, sorcNum - i))
					return false;
			}
		}
		else{
			for (int i = 1; i < destNum - sorcNum; i++){
				if (!board->checkIfClear(destLet, sorcNum + i))
					return false;
			}
		}
	}
	if (sorcNum == destNum){
		if (sorcLet > destLet){
			for (int i = 1; i < sorcLet - destLet; i++){
				if (!board->checkIfClear(sorcLet - 1, destNum))
					return false;
			}
		}
		else{
			for (int i = 1; i < destLet - sorcLet; i++){
				if (!board->checkIfClear(sorcLet + 1, destNum))
					return false;
			}
		}
	}
	return true;
}

/*
The function checks if the move the player did with the queen, is valid.
*/
bool Queen::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	Board* board = static_cast<Board*>(bor);
	if (rookMove(board, sorcLet, sorcNum, destLet, destNum) || bishopMove(board, sorcLet, sorcNum, destLet, destNum))
		return true;
	return false;
}

