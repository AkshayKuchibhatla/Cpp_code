#include "game.h"
#include "Rectangle.h"
#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

Game::Game(const char* title, int x, int y, int w, int h, Uint32 flags, int r, int g, int b, int a) {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->_WINDOW = SDL_CreateWindow(title, x, y, w, h, flags);
    this->_RENDERER = SDL_CreateRenderer(_WINDOW, -1, 0);
    this->_GAMESTATE = PLAY;

    this->backgroundColor = vector<int>(4,0);
    this->backgroundColor[0] = r;
    this->backgroundColor[1] = g;
    this->backgroundColor[2] = b;
    this->backgroundColor[3] = a;
};
Game::~Game() {};

void Game::clearScreen() {
    usleep(20000);
    SDL_SetRenderDrawColor(
        this->_RENDERER, 
        this->backgroundColor[0], 
        this->backgroundColor[1], 
        this->backgroundColor[2], 
        this->backgroundColor[3]
    );
    SDL_RenderClear(this->_RENDERER);
}

void Game::updateScreen() {
    SDL_RenderPresent(this->_RENDERER);
}