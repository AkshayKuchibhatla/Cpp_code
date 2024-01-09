#include <iostream>
#include "game.h"
#include "Rectangle.h"
using namespace std;

enum ColorChangeStatus {ASCENDING, DESCENDING};

int main(int argc, char* argv[]) {
    int SCREEN_WIDTH = 1024;
    int SCREEN_HEIGHT = 600;
    Game game("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, 
    SCREEN_HEIGHT, SDL_WINDOW_SHOWN, 0, 0, 0, 100);
    cout << "Starting game..." << endl;

    Rectangle recy(312, 100, 400, 400, 0, 0, 0, 0);
    ColorChangeStatus status = ASCENDING;

    while (game._GAMESTATE != EXIT) {
        SDL_Event evnt;
        SDL_PollEvent(&evnt);

        game.clearScreen();
        recy.draw(game._RENDERER);
        game.updateScreen();

        if (status == ASCENDING) {
            if (recy.fillColor[0] < 255) {
                recy.fillColor[0] += 5;
                recy.fillColor[1] += 5;
                recy.fillColor[2] += 5;
                recy.fillColor[3] += 5;

                recy.rectangle.x++;
                recy.rectangle.h++;
                recy.rectangle.w++;
            } else {
                status = DESCENDING;
            }
        }

        if (status == DESCENDING) {
            if (recy.fillColor[0] > 0) {
                recy.fillColor[0] -= 5;
                recy.fillColor[1] -= 5;
                recy.fillColor[2] -= 5;
                recy.fillColor[3] -= 5;

                recy.rectangle.x--;
                recy.rectangle.h--;
                recy.rectangle.w--;
            } else {
                status = ASCENDING;
            }
        }

        switch (evnt.type) {
            case SDL_QUIT:
                game._GAMESTATE = EXIT;
                break;
        }
    }
    
    return 0;
}