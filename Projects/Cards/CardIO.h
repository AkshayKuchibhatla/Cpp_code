#include "Deck.h"

struct CardIO {
    /* If the Card object has a deck
    and the deck object has a cards, 
    that means that both circularly 
    import one another. This leads to
    an error. Thus, CardIO is needed 
    in order to mix the two and make a 
    game.*/
    /* "CardIO" stands for "Card Input Output".
    This is the input and output layer
    for the Card files. */
    Deck deck;
    CardIO();
    CardIO(int deckSize);
};