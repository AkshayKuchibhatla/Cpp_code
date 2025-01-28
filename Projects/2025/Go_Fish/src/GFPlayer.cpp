#include "GFPlayer.h"
#include "GoFish.h"
#include <iostream>

GFPlayer::GFPlayer() {}
GFPlayer::GFPlayer(int number) {
    this->playerNumber = number;
    this->handFaceUp = false;

    switch (playerNumber) {
        case 0:
            startRow = 35;
            startCol = 35;
            questionCol = 35;
            questionRow = 25;
            promptCol = 35;
            promptRow = 30;
            answerCol = 35;
            answerRow = 34;
            break;
        case 1:
            startRow = 2;
            startCol = 35;
            questionCol = 35;
            questionRow = 25;
            promptCol = 35;
            promptRow = 30;
            answerCol = 35;
            answerRow = 7;
            break;
    }
}
void GFPlayer::removeCard(int index) {
    hand.erase(hand.begin() + index);
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
vector<string> GFPlayer::getBooks() {
    return books;
}
void GFPlayer::renderHand() {
    int i;
    
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
    hand.push_back(c);
}