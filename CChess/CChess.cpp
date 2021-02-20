#include "SDL.h"
#include <iostream>
#include <string>

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

    SDL_Quit();
}

int main(int argc, char* argv[]) {
    bool quit = false;
    SDL_Event e;
    gRender = NULL;
    int xpos = 0;
    int ypos = 0;

    if (!init()) {
        cout << "Failed to init\n";
    }
    else {

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }

                if (e.type == SDL_KEYDOWN) {
                    ypos++;
                    SDL_RenderClear(gRender);
                    cout << "Test";
                }
            }

            SDL_Rect fillRect = { 0, (SCREEN_HEIGHT / 8) * ypos, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };
            SDL_SetRenderDrawColor(gRender, 0x00, 0xFF, 0x00, 0xFF);
            SDL_RenderFillRect(gRender, &fillRect);
            SDL_RenderPresent(gRender);
        }
    }

    close();
    
    return 0;
}