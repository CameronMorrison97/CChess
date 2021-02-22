#pragma once
#include<string>

using std::string;

class ChessLogic
{
public:
	bool validMove = false;
	int turn = 0;
	void firstMove(string pieceToken);
	void endTurn();
};

