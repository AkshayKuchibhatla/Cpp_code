#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rectangle.h"
#include "game.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

Rectangle::Rectangle() {}
Rectangle::Rectangle(int x, int y, int w, int h, int r, int g, int b, int a) {
    this->rectangle.x = x;
    this->rectangle.y = y;
    this->rectangle.w = w;
    this->rectangle.h = h;

    this->fillColor = vector<int>(4,0);
    this->fillColor[0] = r;
    this->fillColor[1] = g;
    this->fillColor[2] = b;
    this->fillColor[3] = a;
}
Rectangle::~Rectangle() {}

void Rectangle::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(
        renderer, 
        this->fillColor[0], 
        this->fillColor[1], 
        this->fillColor[2], 
        this->fillColor[3]
    );
    SDL_RenderFillRect(renderer, &this->rectangle);
}

// Player class functions
Player::~Player() {}
Player* Player::getInstance()  {
    if (instance == NULL) {
        instance = new Player(X, Y, W, H, R, G, B, A);
        instance->xSpeed = 0;
        instance->ySpeed = 0;
        instance->xMovement = NONE;
        return instance;
    } else {
        return instance;
    }
}

void Player::checkEdges() {
    if (this->rectangle.x + this->rectangle.w > Game::SCREEN_WIDTH) {
        this->rectangle.x = Game::SCREEN_WIDTH - this->rectangle.w;
        this->xSpeed *= -1;
    }
    if (this->rectangle.x < 0) {
        this->rectangle.x = 0;
        this->xSpeed *= -1;
    }
    if (this->rectangle.y + this->rectangle.h > Game::SCREEN_HEIGHT) {
        this->rectangle.y = Game::SCREEN_HEIGHT - this->rectangle.h;
        this->ySpeed = 0;
    }
    if (this->rectangle.y < 0) {
        this->rectangle.y = 0;
        this->ySpeed = 0;
    }
}
void Player::checkPlatforms() {
    
}

// bool Player::isTouchingPlatform() {
//     for (int i = 0; i < Game::platforms.size(); i++) {
//         if (this->isTouchingPlatform(Game::platforms[i])) {
//             return true;
//         }
//     }
//     return false;
// }
bool Player::isTouchingPlatform(Platform p1) {
    int platformMiddleYCoordinate = p1.rectangle.y + (p1.rectangle.h / 2);
    int platformMiddleXCoordinate = p1.rectangle.x + (p1.rectangle.w / 2);
    if (abs(platformMiddleYCoordinate - this->rectangle.y) < p1.rectangle.h / 2
    || abs(platformMiddleYCoordinate - (this->rectangle.y + this->rectangle.h)) < p1.rectangle.h / 2
    || abs(platformMiddleXCoordinate - this->rectangle.x) < p1.rectangle.w / 2
    || abs(platformMiddleXCoordinate - (this->rectangle.x + this->rectangle.x)) < p1.rectangle.w / 2) {
        return true;
    } else {
        return false;
    }
}
bool Player::isTouchingGround() {
    if (this->rectangle.y + this->rectangle.h >= Game::SCREEN_HEIGHT) {
        return true;
    } else {
        return false;
    }
}

// Platform class functions
Platform::~Platform() {}