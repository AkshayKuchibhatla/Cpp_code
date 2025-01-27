#pragma once

#include <string>
#include <vector>

enum Suit {
    NONE,
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Rank {
    JOKER,
    TWO=2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

struct Card {
    Rank rank;
    Suit suit;

    // static const int CARD_HEIGHT = 8;
    // static const int CARD_WIDTH = 10;

    // Constructors
    Card();
    Card(Rank r, Suit s);

    // Pure functions
    std::string to_string();
    bool equals(Card card);
    bool isGreaterThan(Card card);
    bool isLessThan(Card card);
    void draw(int row, int col, bool faceUp, bool narrow);
};

struct Deck {
    std::vector<Card> cardsList;

    Deck(int size);
    Deck();

    void print();
    void swapItems(int index1, int index2);
    void shuffle();
    void selectionSort();
    void addCard(Card card);

    int binarySearch(Card& card, int low, int high);
    int findCard(Card& card);
    int lowestCardIndex(int low, int high);
    Card drawCard();
    Deck subdeck(int lowerIndex, int upperIndex);
    Deck merge(Deck deck);
    Deck mergeSort();
};