#include <iostream>
#include <vector>
#include "Deck.h"
#include "Card.h"
using namespace std;

Deck::Deck(int size) {
    vector<Card> temp(size);
    this->cards = temp;
}
Deck::Deck() {
    vector<Card> deck(52);
    int i = 0;
    for (Suit s = Suit(0); s < SPADES; s = Suit(s + 1)) {
        for (Rank r = Rank(2); r < ACE; r = Rank(r + 1)) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    this->cards = deck;
}

void Deck::print() {
    for (int i = 0; i < this->cards.size(); i++) {
        cout << this->cards[i].to_string() << endl;
    }
}
void Deck::swapItems(int index1, int index2) {
    vector<Card>* listPointer = &this->cards;
    Card* firstElement = &listPointer->at(index1);
    Card* secondElement = &listPointer->at(index2);
    Card temp;
    temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
    delete listPointer;
    delete firstElement;
    delete secondElement;
}
void Deck::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cards.size(); i++) {
        swapItems(i, rand() % this->cards.size());
    }
}

int Deck::binarySearch(Card& card, int low, int high) {
    int middle = (low + high) / 2;
    if (low > high) return -1;
    if (this->cards[middle].equals(card)) return middle;
    
    if (this->cards[middle].isGreaterThan(card)) {
        return binarySearch(card, low, middle-1);
    } else {
        return binarySearch(card, middle+1, high);
    }
}
Deck Deck::subdeck(int lowerIndex, int upperIndex) {
    Deck sub(1);

    for (int i = 0; i < sub.cards.size(); i++) {
        sub.cards.push_back(this->cards[lowerIndex + i]);
    }
    return sub;
}
int Deck::findCard(Card& card) {
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i].equals(card)) return i;
    }
    return -1;
}