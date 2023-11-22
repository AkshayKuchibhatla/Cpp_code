#include "Card.h"

struct Deck {
    std::vector<Card> cards;

    Deck::Deck(int size);
    Deck::Deck();

    void Deck::print();
    void Deck::swapItems(int index1, int index2);
    void Deck::shuffle();
    void Deck::sort();
    void Deck::addCard(Card card);

    int Deck::binarySearch(Card& card, int low, int high);
    int Deck::findCard(Card& card);
    Deck Deck::subdeck(int lowerIndex, int upperIndex);
};