#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"
using namespace std;

Card::Card(bool deck) {
    /* This constructor will create a default deck
    if true is passed to it, otherwise it will create
    just a default single card.*/
    if (deck) {
        this->deck();
        delete this->suit;
        delete this->rank;
    } else {
        /* Creates a single ace of spades by default. 
        No deck is created. This is to ensure that the
        individual cards in decks don't have their OWN
        decks in them unnecessarily.*/
        this->rank = ACE;
        this->suit = CLUBS;
        delete this->deck;
    }
}
Card::Card(Rank r, Suit s) {
    /* Creates the card of mentioned suit and rank.
    Doesn't make a deck.*/
    this->rank = r;
    this->suit = s;
    delete this->deck;
}
Card::Card(int decksize) {
    /* Makes a deck object only. Decks don't need
    suit or rank.*/
    this->deck(decksize);
    delete this->rank;
    delete this->suit;
}


string Card::to_string() {
    string s;
    string r;
    switch (this->suit) {
    case NONE:
        s = "";
    case CLUBS:
        s = "Clubs"; 
        break;
    case DIAMONDS:
        s = "Diamonds"; 
        break;
    case HEARTS:
        s = "Hearts"; 
        break;
    case SPADES:
        s = "Spades"; 
        break;
    default:
        s = "CLUBS";
        break;
    }

    switch (this->rank) {
    case JOKER:
        r = "Joker";
        return r;
    case TWO:
        r = "Two"; 
        break;
    case THREE:
        r = "Three"; 
        break;
    case FOUR:
        r = "Four"; 
        break;
    case FIVE:
        r = "Five"; 
        break;
    case SIX:
        r = "Six"; 
        break;
    case SEVEN:
        r = "Seven"; 
        break;
    case EIGHT:
        r = "Eight"; 
        break;
    case NINE:
        r = "Nine"; 
        break;
    case TEN:
        r = "Ten"; 
        break;
    case JACK:
        r = "Jack"; 
        break;
    case QUEEN:
        r = "Queen"; 
        break;
    case KING:
        r = "King"; 
        break;
    case ACE:
        r = "Ace"; 
        break;
    default:
        r = "Two";
        break;
    }

    return r + " of " + s;
}
bool Card::equals(Card card) {
    return (this->rank == card.rank && this->suit == card.suit);
}
bool Card::isGreaterThan(Card card) {
    if (this->suit > card.suit) return true;
    if (this->suit < card.suit) return false;

    if (this->rank > card.rank) return true;
    if (this->rank < card.rank) return false;

    return false;
}