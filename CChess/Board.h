#pragma once
#include "Click.h"
#include "SDL.h"
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
	void drawBoard(SDL_Renderer*& gRender, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Rect& rectstuff, SDL_Texture* pawnTexture, SDL_Texture* rookTexture, SDL_Texture* knightTexture, SDL_Texture* bishopTexture);
};

