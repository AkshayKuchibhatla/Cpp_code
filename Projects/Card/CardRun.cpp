#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

bool equals(Card c1, Card c2) {
    return (c1.suit == c2.suit && c1.rank == c2.rank);
}

int main() {
    Card ace_of_spades(1,3);
    Card definitely_not_ace_of_spades(2,3);
    cout << ace_of_spades.equals(definitely_not_ace_of_spades) << endl;
    cout << equals(ace_of_spades, definitely_not_ace_of_spades) << endl;

    vector<Card> deck(52);
    return 0;
}