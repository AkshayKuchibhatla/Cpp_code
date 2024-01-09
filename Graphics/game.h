#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;

enum GameState {PLAY, EXIT};

class Game {
    private:
        SDL_Window* _WINDOW;
        vector<int> backgroundColor;

    public:
        GameState _GAMESTATE;
        SDL_Renderer* _RENDERER;

        ~Game();
        Game(const char* title, int x, int y, int w, int h, Uint32 flags, int r, int g, int b, int a);
        void clearScreen();
        void updateScreen();
};