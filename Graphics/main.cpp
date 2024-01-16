#include <iostream>
#include "game.h"
#include "Rectangle.h"
#include <unistd.h>
#include <SDL2/SDL.h>
using namespace std;

// First, initialize the singleton classes:
Player *Player::instance = NULL;

int main(int argc, char* argv[]) {
    Game game("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCREEN_WIDTH, 
    Game::SCREEN_HEIGHT, SDL_WINDOW_SHOWN, 0, 0, 0, 100);
    cout << "Starting game..." << endl;

    Player *MC = Player::getInstance(); // MC = Main Character.

    const float gravity = 2;
    const float friction = 0.7;
    const float airResistance = 0.9;

    while (game._GAMESTATE != EXIT) {
        usleep(16667);
        SDL_Event evnt;
        SDL_PollEvent(&evnt);

        game.clearScreen();

        switch(evnt.type) {
            case SDL_QUIT:
                game._GAMESTATE = EXIT;
                break;

            case SDL_KEYDOWN:
               { const Uint8 *keyboardState = SDL_GetKeyboardState(0);

                if (keyboardState[SDL_SCANCODE_W]) {
                    if (MC->rectangle.y > Game::SCREEN_HEIGHT - MC->rectangle.h - 10) 
                        MC->ySpeed = -20;
                }
                if (keyboardState[SDL_SCANCODE_A]) {
                    MC->xMovement = LEFT;
                }
                if (keyboardState[SDL_SCANCODE_S]) {
                    if (MC->rectangle.y > 0) 
                        MC->ySpeed = 20;
                }
                if (keyboardState[SDL_SCANCODE_D]) {
                    MC->xMovement = RIGHT;
                }
                if (keyboardState[SDL_SCANCODE_LSHIFT] || keyboardState[SDL_SCANCODE_RSHIFT]) {
                    MC->xMovement = NONE;
                    MC->xSpeed = 0;
                }
                break;}

            case SDL_KEYUP:
                MC->xMovement = NONE;
                // yMovement = NONE;
                break;
        }

        if (MC->xMovement == LEFT) {
            MC->xSpeed = -12;
        }
        if (MC->xMovement == RIGHT) {
            MC->xSpeed = 12;
        }

        MC->rectangle.y += MC->ySpeed;
        MC->ySpeed += gravity;
        MC->rectangle.x += MC->xSpeed;

        if (MC->isTouchingGround()) {
            MC->xSpeed *= friction;
        } else {
            MC->xSpeed *= airResistance;
        }

        MC->checkEdges();
        // if (MC->isTouchingPlatform()) {
        //     cout << "Touching platform.";
        // }

        MC->draw(game._RENDERER);
        // game.drawPlatforms();
        game.updateScreen();
    }
    
    return 0;
}