#include <iostream>
#include <vector>
// #include "Deck.h"
#include "Card.h"
using namespace std;

Deck::Deck(int size) {
    this->cardsList = vector<Card> (size);
}
Deck::Deck() {
    vector<Card> deck(52);
    int i = 0;
    for (Suit s = CLUBS; s <= SPADES; s = Suit(s + 1)) {
        for (Rank r = TWO; r <= ACE; r = Rank(r + 1)) {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    this->cardsList = deck;
}

void Deck::print() {
    // Prints every card in the deck, line by line.
    for (int i = 0; i < this->cardsList.size(); i++) {
        cout << this->cardsList[i].to_string() << endl;
    }
}
void Deck::swapItems(int index1, int index2) {
    vector<Card>* listPtr = &this->cardsList;
    Card* firstElementptr = &listPtr->at(index1);
    Card* secondElementptr = &listPtr->at(index2);
    Card temp;
    temp = *firstElementptr;
    *firstElementptr = *secondElementptr;
    *secondElementptr = temp;
    delete listPtr;
    delete firstElementptr;
    delete secondElementptr;
}
void Deck::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cardsList.size(); i++) {
        swapItems(i, rand() % this->cardsList.size());
    }
}
void Deck::addCard(Card card) {
    this->cardsList.push_back(card);
}

int Deck::binarySearch(Card& card, int low, int high) {
    int middle = (low + high) / 2;
    if (low > high) return -1;
    if (this->cardsList[middle].equals(card)) return middle;
    
    if (this->cardsList[middle].isGreaterThan(card)) {
        return binarySearch(card, low, middle-1);
    } else {
        return binarySearch(card, middle+1, high);
    }
}
Deck Deck::subdeck(int lowerIndex, int upperIndex) {
    Deck sub(1);

    for (int i = 0; i < sub.cardsList.size(); i++) {
        sub.cardsList.push_back(this->cardsList[lowerIndex + i]);
    }
    return sub;
}
int Deck::findCard(Card& card) {
    for (int i = 0; i < this->cardsList.size(); i++) {
        if (this->cardsList[i].equals(card)) return i;
    }
    return -1;
}