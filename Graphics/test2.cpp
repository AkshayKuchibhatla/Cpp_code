#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <iostream>
#include <unistd.h>
using namespace std;

class Rectangle {
    SDL_Renderer *localRenderer;

    public:
        SDL_Rect rectangle;
        Rectangle(int x, int y, int height, int width, SDL_Renderer *localRenderer) {
            rectangle.x = x;
            rectangle.y = y;
            rectangle.h = height;
            rectangle.w = width;
            this->localRenderer = localRenderer;
        }
        void draw() {
            SDL_RenderFillRect(this->localRenderer, &this->rectangle);
        }
};

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    Rectangle recy(50, 20, 100, 50, renderer);

    bool quit = false;
    while (!quit) {
        SDL_Event e;
        SDL_WaitEvent(&e);
        if(e.type == SDL_QUIT) {
            quit = true;
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            recy.rectangle.x++;
            recy.draw();
            SDL_RenderPresent(renderer);
        }
        usleep(10000);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}