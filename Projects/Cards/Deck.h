#include "Card.h"
#include <vector>

#ifndef DECK_H
#define DECK_H

struct Deck {
    std::vector<Card> cardsList;

    Deck(int size);
    Deck();

    void print();
    void swapItems(int index1, int index2);
    void shuffle();
    void mergeSort();
    void addCard(Card card);

    int binarySearch(Card& card, int low, int high);
    int findCard(Card& card);
    Deck subdeck(int lowerIndex, int upperIndex);
};
#endif