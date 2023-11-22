#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    Card defaultCard(true);
    cout << defaultCard.to_string();
    return 0;
}