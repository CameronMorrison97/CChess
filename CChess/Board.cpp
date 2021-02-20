#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;
using std::array;

array<int,2> Board::translateClickToGrid(Click clk, int screenHeight, int screenWidth)
{
	array<int, 2> gridCoords;

	if (clk.mouseDown.x >= 0 && clk.mouseDown.x <= (screenWidth / 8)) {
		gridCoords[0] = 0;
	}else if (clk.mouseDown.x > (screenWidth / 8) && clk.mouseDown.x <= (screenWidth / 8) * 2) {
		gridCoords[0] = 1;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 2 && clk.mouseDown.x <= (screenWidth / 8) * 3) {
		gridCoords[0] = 2;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 3 && clk.mouseDown.x <= (screenWidth / 8) * 4) {
		gridCoords[0] = 3;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 4 && clk.mouseDown.x <= (screenWidth / 8) * 5) {
		gridCoords[0] = 4;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 5 && clk.mouseDown.x <= (screenWidth / 8) * 6) {
		gridCoords[0] = 5;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 6 && clk.mouseDown.x <= (screenWidth / 8) * 7) {
		gridCoords[0] = 6;
	}else if (clk.mouseDown.x > (screenWidth / 8) * 7 && clk.mouseDown.x <= screenWidth) {
		gridCoords[0] = 7;
	}

	if (clk.mouseDown.y >= 0 && clk.mouseDown.y <= (screenHeight / 8)) {
		gridCoords[1] = 0;
	}else if (clk.mouseDown.y > (screenHeight / 8) && clk.mouseDown.y <= (screenHeight / 8) * 2) {
		gridCoords[1] = 1;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 2 && clk.mouseDown.y <= (screenHeight / 8) * 3) {
		gridCoords[1] = 2;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 3 && clk.mouseDown.y <= (screenHeight / 8) * 4) {
		gridCoords[1] = 3;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 4 && clk.mouseDown.y <= (screenHeight / 8) * 5) {
		gridCoords[1] = 4;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 5 && clk.mouseDown.y <= (screenHeight / 8) * 6) {
		gridCoords[1] = 5;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 6 && clk.mouseDown.y <= (screenHeight / 8) * 7) {
		gridCoords[1] = 6;
	}else if (clk.mouseDown.y > (screenHeight / 8) * 7 && clk.mouseDown.y <= screenHeight) {
		gridCoords[1] = 7;
	}

	return gridCoords;
}


array<int, 2> translateClickToGridMouseUp(Click clk, int screenHeight, int screenWidth) {
	array<int, 2> gridCoords;

	if (clk.mouseUp.x >= 0 && clk.mouseUp.x <= (screenWidth / 8)) {
		gridCoords[0] = 0;
	}else if (clk.mouseUp.x > (screenWidth / 8) && clk.mouseUp.x <= (screenWidth / 8) * 2) {
		gridCoords[0] = 1;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 2 && clk.mouseUp.x <= (screenWidth / 8) * 3) {
		gridCoords[0] = 2;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 3 && clk.mouseUp.x <= (screenWidth / 8) * 4) {
		gridCoords[0] = 3;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 4 && clk.mouseUp.x <= (screenWidth / 8) * 5) {
		gridCoords[0] = 4;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 5 && clk.mouseUp.x <= (screenWidth / 8) * 6) {
		gridCoords[0] = 5;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 6 && clk.mouseUp.x <= (screenWidth / 8) * 7) {
		gridCoords[0] = 6;
	}else if (clk.mouseUp.x > (screenWidth / 8) * 7 && clk.mouseUp.x <= screenWidth) {
		gridCoords[0] = 7;
	}

	if (clk.mouseUp.y >= 0 && clk.mouseUp.y <= (screenHeight / 8)) {
		gridCoords[1] = 0;
	}else if (clk.mouseUp.y > (screenHeight / 8) && clk.mouseUp.y <= (screenHeight / 8) * 2) {
		gridCoords[1] = 1;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 2 && clk.mouseUp.y <= (screenHeight / 8) * 3) {
		gridCoords[1] = 2;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 3 && clk.mouseUp.y <= (screenHeight / 8) * 4) {
		gridCoords[1] = 3;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 4 && clk.mouseUp.y <= (screenHeight / 8) * 5) {
		gridCoords[1] = 4;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 5 && clk.mouseUp.y <= (screenHeight / 8) * 6) {
		gridCoords[1] = 5;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 6 && clk.mouseUp.y <= (screenHeight / 8) * 7) {
		gridCoords[1] = 6;
	}else if (clk.mouseUp.y > (screenHeight / 8) * 7 && clk.mouseUp.y <= screenHeight) {
		gridCoords[1] = 7;
	}

	return gridCoords;
}
