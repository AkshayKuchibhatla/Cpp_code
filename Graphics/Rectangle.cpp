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

bool Rectangle::overlaps(Rectangle r) {

    // if rectangle has area 0, no overlap
    if (this->rectangle.x == this->rectangle.x + this->rectangle.w 
    || this->rectangle.y == this->rectangle.y + this->rectangle.h 
    || r.rectangle.x + r.rectangle.w == r.rectangle.x 
    || r.rectangle.y == r.rectangle.y + r.rectangle.h) {
        return false;
    }
    // If one rectangle is on left side of other
    if (this->rectangle.x > r.rectangle.x + r.rectangle.w 
    || r.rectangle.x > this->rectangle.x + this->rectangle.w) {
        return false;
    }
    // If one rectangle is above other
    if (this->rectangle.y + this->rectangle.h < r.rectangle.y 
    || r.rectangle.y + r.rectangle.h < this->rectangle.y) {
        return false;
    }
    return true;
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

void Player::switchXDirection() {
    if (this->xMovement == LEFT) this->xMovement = RIGHT;
    if (this->xMovement == RIGHT) this->xMovement = LEFT;
}
void Player::checkEdges() {
    if (this->rectangle.x + this->rectangle.w > Game::SCREEN_WIDTH) {
        this->rectangle.x = Game::SCREEN_WIDTH - this->rectangle.w;
        this->xSpeed *= -1;
        this->switchXDirection();
    }
    if (this->rectangle.x < 0) {
        this->rectangle.x = 0;
        this->xSpeed *= -1;
        this->switchXDirection();
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
void Player::checkPlatforms(vector<Platform> platforms) {
    /* This is a work in progress.*/
    int platformMiddleX;
    int platformMiddleY;
    for (int i = 0; i < platforms.size(); i++) {
        platformMiddleX = platforms[i].rectangle.x + (platforms[i].rectangle.w / 2);
        platformMiddleY = platforms[i].rectangle.y + (platforms[i].rectangle.h / 2);
        if (abs(this->rectangle.x + this->xSpeed - platformMiddleX) < platforms[i].rectangle.w / 2
        && abs(this->rectangle.y + this->ySpeed - platformMiddleY) < platforms[i].rectangle.h / 2) {
            if (this->xSpeed < 0) {
                this->rectangle.x = platforms[i].rectangle.x + platforms[i].rectangle.w;
            } else {
                this->rectangle.x = platforms[i].rectangle.x - this->rectangle.w;
            }

            if (this->ySpeed < 0) {
                this->rectangle.y = platforms[i].rectangle.y - this->rectangle.h;
            } else {
                this->rectangle.y = platforms[i].rectangle.y + platforms[i].rectangle.h;
            }
        }
    }
    return;
}

bool Player::isTouchingPlatform(vector<Platform> platforms) {
    for (int i = 0; i < platforms.size(); i++) {
        if (this->overlaps(platforms[i])) {
            return true;
        }
    }
    return false;
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