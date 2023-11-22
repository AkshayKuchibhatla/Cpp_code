#include <iostream>
#include "CardIO.h"
#include "Deck.h"
using namespace std;

CardIO::CardIO() {
    this->deck = Deck();
}

CardIO::CardIO(int deckSize) {
    this->deck = Deck(deckSize);
}