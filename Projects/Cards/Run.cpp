#include <iostream>
#include "Card.h"
using namespace std;

int main() {
    Deck deck = Deck();
    Card diamondJack = Card(JACK, DIAMONDS);
    cout << deck.findCard(diamondJack);
    // deck.print();
    return 0;
}