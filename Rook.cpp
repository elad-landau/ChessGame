#include "Rook.h"

Rook::Rook(bool color) : Piece(color){}

bool Rook::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum)
{
	Board* board = static_cast<Board*>(bor);
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