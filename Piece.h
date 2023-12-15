#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:

	Piece(bool color);
	virtual bool checkMove(void* bor, int sorcLet, int sorcNum, int destLet, int destNum);
	bool getColor();

protected:

	// color: true- black, false- white
	bool _color;

};
#endif