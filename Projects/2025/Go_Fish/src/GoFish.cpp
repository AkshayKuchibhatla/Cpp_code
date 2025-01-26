#include "GoFish.h"
using namespace std;

GoFish::GoFish() {
    GoFish(2);
}
GoFish::GoFish(int numberOfPlayers) {
    Deck fishPile();
    this->fishPile.shuffle();
    this->fishPile.cardsList[0].draw(20, 20, true, false);
}