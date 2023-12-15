#include "Board.h"



//A constructor to the board at the start of the game
Board::Board()
{
	int i;
	for (i = 0; i < 8; i++)
		_board[i][1] = new Pawn(false);
	for (i = 0; i < 8; i++)
		_board[i][6] = new Pawn(true);
	bool color = false;
	int row = 0;
	for (i = 0; i < 2; i++)
	{
		i == 1 ? color = true, row = 7 : 0;

		_board[0][row] = new Rook(color);
		_board[1][row] = new Knight(color);
		_board[2][row] = new Bishop(color);
		_board[3][row] = new King(color);
		_board[4][row] = new Queen(color);
		_board[5][row] = new Bishop(color);
		_board[6][row] = new Knight(color);
		_board[7][row] = new Rook(color);
	}
	for (i = 2; i < 6; i++){
		for (int j = 0; j < 8; j++){
			_board[j][i] = NULL;
		}
	}
}

// a destructor for the board
Board::~Board()
{
	for (int i = 0; i > 8; i++){
		for (int j = 0; j < 8; j++){
			if (&(_board[i][j]) != NULL){
				delete &(_board[i][j]);
			}
		}
	}
}


/*
The function checks if the move the player did any Piece, is valid and returns a number according to the
rule that was violated.
returns 0 - if there was no violation
*/
char* Board::checkMove(string move)
{
	// transfer the string from the fronthead to numbers
	char cordinates[4];
	for (int i = 0; i < 4; i++){
		cordinates[i] = move.at(i);
	}
	int sorcLet = ((int)*cordinates) - 97;
	int sorcNum = (int)*(cordinates + 1) - 49;
	int destLet = (int)*(cordinates + 2) - 97;
	int destNum = (int)*(cordinates + 3) - 49;

	// checks if the sorce and destination of the piece are the same
	if (sorcLet == destLet && sorcNum == destNum)
		return "7";

	// checks if the given sorce and destination are within the board's borders 
	if (!(sorcLet >= 0 && sorcLet <= 7 && sorcNum >= 0 && sorcNum <= 7 && destLet >= 0 && destLet <= 7 && destNum >= 0 && destNum <= 7))
		return "5";

	// check if the right colored player was selected according to the turn
	if (checkIfClear(sorcLet, sorcNum))
		return "2";
	if (turn != (_board[sorcLet][sorcNum]->getColor()))
		return "2";


	// checks if you haven't eaten your own pieces
	if (!checkIfClear(destLet, destNum))
	{
		if (turn == (_board[destLet][destNum]->getColor()))
			return "3";
	}

	// checks if the movement of the piece itself was legal
	if (!(_board[sorcLet][sorcNum]->checkMove(this, sorcLet, sorcNum, destLet, destNum)))
		return "6";

	// checks if the movement has caused chess on the player that made the movement
	if (checkIfChess(destLet, destNum, sorcLet, sorcNum) == 1)
		return "4";

	// allows movement of the pieces
	eatTool(sorcNum, sorcLet, destNum, destLet);

	// checks if the movement has caused chess on the player that didn't made the movement
	if (checkIfChess(destLet, destNum, sorcLet, sorcNum) == 2){
		return "1";
	}

	return "0";
}

/*
The function checks if there is a chess on the board after every move
*/
int Board::checkIfChess(int destLet, int destNum, int sorcLet, int sorcNum)
{
	Piece *currKing = NULL, *otherKing = NULL, *eatenTool = NULL;
	string classType;
	int CkingLet, CkingNum, OkingLet, OkingNum;


	//checks where both of the kings are and saves their coordinates 
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (checkIfClear(i, j)){
				classType = "\0";
			}
			else{
				classType = typeid(*_board[i][j]).name();
			}
			if (classType.compare("class King") == 0){
				if (_board[i][j]->getColor() == turn){
					currKing = _board[i][j];
					CkingLet = i;
					CkingNum = j;
				}
				if (_board[i][j]->getColor() != turn){
					otherKing = _board[i][j];
					OkingLet = i;
					OkingNum = j;
				}
			}
		}
	}

	// checks if the king can move to a certain place without being threatend
	if (_board[sorcLet][sorcNum] == currKing){
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (_board[i][j] != NULL && _board[i][j]->getColor() != turn){
					if (_board[i][j]->checkMove(this, i, j, destLet, destNum)){
						return 1;
					}
				}
			}
		}
	}

	// checks if one of the pieces can move to a certain place withput the king being threatend
	if (_board[sorcLet][sorcNum] != currKing && _board[sorcLet][sorcNum] != otherKing){

		if (_board[destLet][destNum] != NULL){
			eatenTool = _board[destLet][destNum];
		}
		_board[destLet][destNum] = _board[sorcLet][sorcNum];
		_board[sorcLet][sorcNum] = NULL;
		int result = checkIfChess(CkingLet, CkingNum, CkingLet, CkingNum);
		_board[sorcLet][sorcNum] = _board[destLet][destNum];
		_board[destLet][destNum] = eatenTool;
		if (result == 1)
			return 1;
	}

	// checks if the king of the other player is being threatend
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (_board[i][j] != NULL && _board[i][j]->getColor() == turn){
				if (_board[i][j]->checkMove(this, i, j, OkingLet, OkingNum)){
					return 2;
				}
			}
		}
	}
	return 0;
}

// The function move the pieces and in case of an eaten piece, removes the piece of the board
void Board::eatTool(int sorcNum, int sorcLet, int destNum, int destLet)
{
	if (_board[destLet][destNum] != NULL)
		delete _board[destLet][destNum];
	_board[destLet][destNum] = _board[sorcLet][sorcNum];
	_board[sorcLet][sorcNum] = NULL;
	turn == true ? turn = false : turn = true;
}
// the function checks if in the given location there is a piece or not
bool Board::checkIfClear(int line, int row)
{
	if (_board[line][row] == NULL)
		return true;
	return false;
}
