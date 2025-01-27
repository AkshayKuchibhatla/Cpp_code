#include "GFPlayer.h"
#include "GoFish.h"
#include <iostream>

GFPlayer::GFPlayer() {}
GFPlayer::GFPlayer(int number) {
    this->playerNumber = number;
    this->handFaceUp = false;
}
void GFPlayer::hideHand() {
    this->handFaceUp = false;
}
void GFPlayer::showHand() {
    this->handFaceUp = true;
}
vector<Card> GFPlayer::getHand() {
    return this->hand;
}
void GFPlayer::renderHand() {
    int startRow, startCol, i;
    switch(this->playerNumber) {
        case 0:
            startRow = 35;
            startCol = 35;
            break;
        case 1:
            startRow = 2;
            startCol = 35;
            break;
        case 2:
            startRow = 5;
            startCol = 10;
            break;
    }
    if (playerNumber == 0 || playerNumber == 1) {
        for (i = 0; i < hand.size(); i++) {
            hand.at(i).draw(startRow, startCol + i * 3, handFaceUp, true);
        }
    }
}
void GFPlayer::printHand() {
    for (int i = 0; i < hand.size(); i++) {
        cout << hand.at(i).to_string() << "\n\r";
    }
}
void GFPlayer::addCard(Card c) {
    // cout << c.to_string() << "\n\r";
    hand.push_back(c);
}