#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rectangle.h"
#include <vector>
using namespace std;

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