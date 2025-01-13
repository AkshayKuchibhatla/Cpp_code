#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rectangle.h"
#include "game.h"
#include <vector>
#include <cmath>
#include <unistd.h>
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
void Player::resolvePlatformCollision(Platform platform) {
    if (this->ySpeed < 0) {
        while (this->rectangle.y < platform.rectangle.y + platform.rectangle.h + 1) {
            this->rectangle.y++;
        } 
    } else if (this->ySpeed > 0) {
        while (this->rectangle.y + this->rectangle.h > platform.rectangle.y - 1) {
            this->rectangle.y--;
        }
    } else {}
    this->ySpeed = 0;

    double lastXPos = this->rectangle.x;
    
    if (xSpeed < 0) {
        while (this->rectangle.x < platform.rectangle.x + platform.rectangle.w + 1) {
            this->rectangle.x++;
        }
    } else if (xSpeed > 0) {
        while (this->rectangle.x + this->rectangle.w > platform.rectangle.x - 1) {
            this->rectangle.x--;
        }
    } else {}
    this->xSpeed = 0;
    // if (this->rectangle.x > platform.rectangle.x + platform.rectangle.w/2) {
    //     this->rectangle.x = platform.rectangle.x + platform.rectangle.w + 1;
    // } else if (this->rectangle.x + this->rectangle.w < platform.rectangle.x) {
    //     this->rectangle.x = platform.rectangle.x - this->rectangle.w - 1;
    // } else {}
}

bool Player::isTouchingPlatform(vector<Platform> platforms) {
    for (int i = 0; i < platforms.size(); i++) {
        if (this->overlaps(platforms[i])) {
            resolvePlatformCollision(platforms[i]);
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