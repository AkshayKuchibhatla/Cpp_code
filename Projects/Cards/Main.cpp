#include <iostream>
#include "CardIO.h"
using namespace std;

int main() {
    CardIO cardIO = CardIO();
    cardIO.deck.shuffle();
    cardIO.deck.print();
    return 0;
}