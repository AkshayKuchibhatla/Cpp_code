#include <iostream>
#include "Card.h"
using namespace std;

Card::Card() {
    this->rank = 0;
    this->suit = 0;
}

Card::Card(int r, int s) {
    this->rank = r;
    this->suit = s;
}