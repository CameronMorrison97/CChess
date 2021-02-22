#include "SDL.h"
#include "SDL_image.h"
#include "Click.h"
#include "Board.h"
#include <iostream>
#include <string>
#include<array>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

using namespace std;

SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* gRender;

bool init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL could not init SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    else {
        window = SDL_CreateWindow("CChess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        gRender = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (window == NULL) {
            cout << "window could not be created! SDL Error: " << SDL_GetError() << endl;
            return false;
        }

        IMG_Init(IMG_INIT_PNG);
    }

    return true;
}

void close() {
    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gRender);
    window = NULL;
    gRender = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    bool quit = false;
    SDL_Event e;
    gRender = NULL;
    int xpos = 0;
    int ypos = 0;

    SDL_Rect rectstuff;

    if (!init()) {
        cout << "Failed to init\n";
    }
    else {
        Board board(gRender);

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                
                if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_DOWN:
                            ypos++;
                            cout << "DOWN";
                            break;
                        case SDLK_UP:
                            ypos--;
                            cout << "UP";
                            break;
                        case SDLK_LEFT:
                            xpos--;
                            cout << "LEFT";
                            break;
                        case SDLK_RIGHT:
                            xpos++;
                            cout << "RIGHT";
                            break;
                    }
                }

                if (e.type == SDL_MOUSEBUTTONDOWN) {
                    switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        Click click;
                        cout << "X Position is : " << e.motion.x << endl;
                        cout << "Y Position is : " << e.motion.y << endl;
                        click.mouseDown.x = e.motion.x;
                        click.mouseDown.y = e.motion.y;

                        array<int, 2> gridLocation = board.translateClickToGrid(click, SCREEN_HEIGHT, SCREEN_WIDTH);
                        board.currentlySelectedLocation = gridLocation;
                    }
                }

                if (e.type == SDL_MOUSEBUTTONUP) {
                    switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        Click click;
                        cout << "X Position is : " << e.motion.x << endl;
                        cout << "Y Position is : " << e.motion.y << endl;
                        click.mouseUp.x = e.motion.x;
                        click.mouseUp.y = e.motion.y;

                        array<int, 2> gridLocation = board.translateClickToGridMouseUp(click, SCREEN_HEIGHT, SCREEN_WIDTH);
                        array<int, 2> oldLocation = board.currentlySelectedLocation;
                        
                        board.movePiece(gridLocation, oldLocation);
                    }
                }
            }

            board.drawBoard(gRender, SCREEN_WIDTH, SCREEN_HEIGHT, rectstuff);
        }
    }

    close();
    
    return 0;
}