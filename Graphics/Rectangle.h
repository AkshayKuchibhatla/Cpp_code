#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;

class Rectangle {
    public:
        SDL_Rect rectangle;
        vector<int> fillColor;

        Rectangle(int x, int y, int w, int h, int r, int g, int b, int a);
        ~Rectangle();

        void draw(SDL_Renderer *renderer);
};