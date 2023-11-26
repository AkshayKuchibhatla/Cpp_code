#include <iostream>
#include "Card.h"
#include "Random.h"
using namespace std;

int main() {
    // Random randObj = Random();
    // cout << "randObj.randomNumberBetween(1, 10): " 
    // << randObj.randomNumberBetween(1, 10) << endl;
    // cout << "randObj.randomNumberBetween(1, 100): " 
    // << randObj.randomNumberBetween(1, 100) << endl;
    // cout << "randObj.randomNumberBetween(10, 10): " 
    // << randObj.randomNumberBetween(10, 10) << endl;
    // cout << "randObj.randomNumberBetween(10, 1): " 
    // << randObj.randomNumberBetween(10, 1) << endl;
    // cout << "randObj.randomNumberBetween(1, 1000): " 
    // << randObj.randomNumberBetween(1, 1000) << endl 
    // << endl << endl;

    // Deck deck = Deck();
    // Card diamondJack = Card(JACK, DIAMONDS);
    // deck.shuffle();
    // cout << "deck.findCard(diamondJack): " 
    // << deck.findCard(diamondJack) << endl << endl;
    // deck.print();

    // cout << "\n\n\n" << deck.lowestCardIndex(0, 10) << ", " 
    // << deck.cardsList[deck.lowestCardIndex(0, 10)].to_string();

    // cout << "\n\n\n";
    // deck.selectionSort();
    // deck.print();

    // cout << "\n\n\n";
    // Deck sub1 = deck.subdeck(0, 10);
    // sub1.print();

    // cout << "\n\n\n";
    // Deck d1 = Deck(6);
    // Deck d2 = Deck(6);
    // for (int i = 0; i < 6; i++) {
    //     d1.cardsList[i] = Card(Rank(i * 2), CLUBS);
    // }
    // for (int i = 1; i < 6; i++) {
    //     d2.cardsList[i] = Card(Rank(i * 2 + 1), CLUBS);
    // }
    // d1.print();
    // cout << endl;
    // d2.print();
    // cout << endl;
    // d1.merge(d2).print();

    Deck deck1 = Deck();
    deck1.print();
    cout << "\n\n\n";
    deck1.shuffle();
    deck1.print();
    cout << "\n\n\n";
    deck1.mergeSort();
    deck1.print();
    return 0;
}