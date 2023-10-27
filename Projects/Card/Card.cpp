#include <iostream>
#include <vector>
#include "Card.h"
using namespace std;

Card::Card() {
    this->rank = 0;
    this->suit = 0;
}
Card::Card(int r, int s) {
    this->rank = r;
    this->suit = s;
}


string Card::to_string() {
    vector<string> suit_strings = {"Clubs", "Diamonds", "Hearts", "Spades"}; 
    vector<string> rank_strings = {"", "Ace", "2", "3", "4", "5", "6", "7",
                                   "8", "9", "10", "Jack", "Queen", "King"};
    
    return rank_strings[this->rank] + "of" + suit_strings[this->suit];
}
bool Card::equals(Card card) {
    return (this->rank == card.rank && this->suit == card.suit);
}
