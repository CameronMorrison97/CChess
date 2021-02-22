#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;
using std::array;

Board::Board(SDL_Renderer*& gRender)
{
	// Draw White pieces
	for (int i = 0; i < 8; i++) {
		board[6][i] = "WP";
	}

	board[7][0] = "WR";
	board[7][7] = "WR";
	board[7][1] = "WK";
	board[7][6] = "WK";
	board[7][2] = "WB";
	board[7][5] = "WB";
	board[7][4] = "WI";
	board[7][3] = "WQ";

	this->whitepawnTexture = IMG_LoadTexture(gRender, "whitePawn.png");
	this->whiterookTexture = IMG_LoadTexture(gRender, "whiteRook.png");
	this->whiteknightTexture = IMG_LoadTexture(gRender, "whiteKnight.png");
	this->whitebishopTexture = IMG_LoadTexture(gRender, "whiteBishop.png");
	this->whitekingTexture = IMG_LoadTexture(gRender, "whiteKing.png");
	this->whitequeenTexture = IMG_LoadTexture(gRender, "whiteQueen.png");

	// Draw Black pieces
	for (int i = 0; i < 8; i++) {
		board[1][i] = "BP";
	}

	board[0][0] = "BR";
	board[0][7] = "BR";
	board[0][1] = "BK";
	board[0][6] = "BK";
	board[0][2] = "BB";
	board[0][5] = "BB";
	board[0][4] = "BI";
	board[0][3] = "BQ";
	
	this->blackpawnTexture = IMG_LoadTexture(gRender, "blackPawn.png");
	this->blackrookTexture = IMG_LoadTexture(gRender, "blackRook.png");
	this->blackknightTexture = IMG_LoadTexture(gRender, "blackKnight.png");
	this->blackbishopTexture = IMG_LoadTexture(gRender, "blackBishop.png");
	this->blackkingTexture = IMG_LoadTexture(gRender, "blackKing.png");
	this->blackqueenTexture = IMG_LoadTexture(gRender, "blackQueen.png");

}

array<int,2> Board::translateClickToGrid(Click clk, int screenHeight, int screenWidth)
{
	array<int, 2> gridCoords = { -1,-1 };

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

void Board::movePiece(array<int,2> gridLocation,array<int,2> oldLocation)
{

	if (board[oldLocation[1]][oldLocation[0]].compare("WP") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WP";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("WR") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WR";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("WK") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WK";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("WB") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WB";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("WI") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WI";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("WQ") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "WQ";
	}

	if (board[oldLocation[1]][oldLocation[0]].compare("BP") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BP";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("BR") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BR";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("BK") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BK";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("BB") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BB";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("BI") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BI";
	}else if (board[oldLocation[1]][oldLocation[0]].compare("BQ") == 0) {
		board[oldLocation[1]][oldLocation[0]] = "";
		board[gridLocation[1]][gridLocation[0]] = "BQ";
	}
}

void Board::drawBoard(SDL_Renderer*& gRender, int SCREEN_WIDTH,int SCREEN_HEIGHT,SDL_Rect& rectstuff)
{
	SDL_RenderClear(gRender);

	SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_SetRenderDrawColor(gRender, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(gRender, &fillRect);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j].compare("WP") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whitepawnTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("WR") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whiterookTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("WK") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whiteknightTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("WB") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whitebishopTexture, NULL, &rectstuff);
			}else if (board[i][j].compare("WI") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whitekingTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("WQ") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, whitequeenTexture, NULL, &rectstuff);
			}

			if (board[i][j].compare("BP") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackpawnTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("BR") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackrookTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("BK") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackknightTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("BB") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackbishopTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("BI") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackkingTexture, NULL, &rectstuff);
			}
			else if (board[i][j].compare("BQ") == 0) {
				rectstuff = { (SCREEN_WIDTH / 8) * j, (SCREEN_HEIGHT / 8) * i, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
				SDL_RenderCopy(gRender, blackqueenTexture, NULL, &rectstuff);
			}
		}
	}



	SDL_RenderPresent(gRender);
}


array<int, 2> Board::translateClickToGridMouseUp(Click clk, int screenHeight, int screenWidth) {
	array<int, 2> gridCoords = { -1,-1 };

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
