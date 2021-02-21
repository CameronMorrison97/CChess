#pragma once
#include "Click.h"
#include <array>

using std::array;

class Board
{
public:
	Board();
	char board[8][8];
	array<int, 2> currentlySelectedLocation;
	array<int,2> translateClickToGrid(Click clk, int screenHeight, int screenWidth);
	array<int, 2> translateClickToGridMouseUp(Click clk, int screenHeight, int screenWidth);
};

