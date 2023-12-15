#include "Piece.h"

Piece::Piece(bool color) : _color(color) {}

bool Piece::getColor(){
	return _color;
}

bool Piece::checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum){
	return false;
}
