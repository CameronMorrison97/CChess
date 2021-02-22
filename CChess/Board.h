#pragma once
#include "Click.h"
#include "SDL.h"
#include "SDL_image.h"
#include "ChessLogic.h"
#include <array>
#include <string>

using std::array;
using std::string;

class Board
{
public:
	Board(SDL_Renderer*& gRender);
	string board[8][8];
	array<int, 2> currentlySelectedLocation;
	array<int,2> translateClickToGrid(Click clk, int screenHeight, int screenWidth);
	array<int, 2> translateClickToGridMouseUp(Click clk, int screenHeight, int screenWidth);
	void drawBoard(SDL_Renderer*& gRender, int SCREEN_WIDTH, int SCREEN_HEIGHT, SDL_Rect& rectstuff);
	void movePiece(array<int, 2> gridLocation, array<int, 2> oldLocation);
	SDL_Texture* whitepawnTexture;
	SDL_Texture* whiterookTexture;
	SDL_Texture* whiteknightTexture;
	SDL_Texture* whitebishopTexture;
	SDL_Texture* whitekingTexture;
	SDL_Texture* whitequeenTexture;

	SDL_Texture* blackpawnTexture;
	SDL_Texture* blackrookTexture;
	SDL_Texture* blackknightTexture;
	SDL_Texture* blackbishopTexture;
	SDL_Texture* blackkingTexture;
	SDL_Texture* blackqueenTexture;
	ChessLogic engine;

	SDL_Texture* Chessboard;
};

