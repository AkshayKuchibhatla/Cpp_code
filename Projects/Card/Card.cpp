#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
using namespace std;

Card::Card() {
    this->rank = ACE;
    this->suit = CLUBS;
}
Card::Card(Rank r, Suit s) {
    this->rank = r;
    this->suit = s;
}


string Card::to_string() {
    string s;
    string r;
    switch (this->suit) {
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