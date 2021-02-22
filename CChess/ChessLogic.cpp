#include "ChessLogic.h"

using std::array;

void ChessLogic::firstMove(string pieceToken)
{
	char isWhite = pieceToken.at(0);
	// Check that first piece moved is a white piece.
	if (isWhite == 'W') {
		validMove = true;
	}
	else {
		validMove = false;
	}
}

void ChessLogic::endTurn() {
	turn++;
	validMove = false;
}
