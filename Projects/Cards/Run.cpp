#include <iostream>
#include "Card.h"
#include "Random.h"
using namespace std;

int main() {
    Random randObj = Random();
    cout << "randObj.randomNumberBetween(1, 10): " 
    << randObj.randomNumberBetween(1, 10) << endl;
    cout << "randObj.randomNumberBetween(1, 100): " 
    << randObj.randomNumberBetween(1, 100) << endl;
    cout << "randObj.randomNumberBetween(10, 10): " 
    << randObj.randomNumberBetween(10, 10) << endl;
    cout << "randObj.randomNumberBetween(10, 1): " 
    << randObj.randomNumberBetween(10, 1) << endl;
    cout << "randObj.randomNumberBetween(1, 1000): " 
    << randObj.randomNumberBetween(1, 1000) << endl 
    << endl << endl;

    Deck deck = Deck();
    Card diamondJack = Card(JACK, DIAMONDS);
    deck.shuffle();
    cout << "deck.findCard(diamondJack): " 
    << deck.findCard(diamondJack) << endl << endl;
    deck.print();

    cout << "\n\n\n" << deck.lowestCardIndex(0, 10) << ", " 
    << deck.cardsList[deck.lowestCardIndex(0, 10)].to_string();

    cout << "\n\n\n";
    deck.selectionSort();
    deck.print();
    return 0;
}