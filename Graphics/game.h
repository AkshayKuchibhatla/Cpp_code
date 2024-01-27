#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rectangle.h"
#include <vector>
using namespace std;

enum GameState {PLAY, EXIT};

class Game {
    private:
        SDL_Window* _WINDOW;
        vector<int> backgroundColor;
        static Game *instance;

    public:
        vector<Platform> _PLATFORMS;
        static const int SCREEN_HEIGHT = 600;
        static const int SCREEN_WIDTH = 1024;

        GameState _GAMESTATE;
        SDL_Renderer* _RENDERER;

        Game();
        ~Game();
        Game(const char* title, int x, int y, int w, int h, Uint32 flags, int r, int g, int b, int a);

        void clearScreen();
        void updateScreen();
        void drawPlatforms();
};
#endif