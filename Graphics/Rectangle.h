#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;

const int X = 0;
const int Y = 0;
const int W = 30;
const int H = 30;
const int R = 0;
const int G = 255;
const int B = 0;
const int A = 100;

enum Direction {
    LEFT,
    RIGHT,
    NONE
};

class Rectangle { // The base class for all objects generated within the game.
    public:
        SDL_Rect rectangle;
        vector<int> fillColor;

        Rectangle();
        Rectangle(int x, int y, int w, int h, int r, int g, int b, int a);
        ~Rectangle();

        void draw(SDL_Renderer *renderer);
};

class Platform: public Rectangle { // A platformer's gotta have platforms.
    public:
        Platform(int x, int y, int w, int h, int r, int g, int b, int a) : 
        Rectangle(x, y, w, h, r, g, b, a) {};
        Platform() : Rectangle() {};
        ~Platform();
};

class Player: public Rectangle { // Singleton class of the player.
    private:
        static Player* instance;
        
    public:
        Direction xMovement;
        float xSpeed;
        float ySpeed;

        static Player* getInstance();

        Player(int x, int y, int w, int h, int r, int g, int b, int a) : 
        Rectangle(x, y, w, h, r, g, b, a) {};
        Player() : Rectangle() {};
        ~Player();

        void checkEdges();
        void checkPlatforms();

        bool isTouchingPlatform();
        bool isTouchingPlatform(Platform p1);
        bool isTouchingGround();
};