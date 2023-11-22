#include "Deck.h"

enum Suit {
    NONE=-1,
    CLUBS=0,
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
    Deck deck;

    // Constructors
    Card(bool deck);
    Card(Rank r, Suit s);
    Card(int deckSize);

    // Pure functions
    std::string to_string();
    bool equals(Card card);
    bool isGreaterThan(Card card);
};