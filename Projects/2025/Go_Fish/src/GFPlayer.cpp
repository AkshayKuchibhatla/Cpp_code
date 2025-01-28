#include <ncurses.h>
#include "GFPlayer.h"
#include "GoFish.h"
#include <iostream>
#include <unistd.h>

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

            booksRow = 32;
            booksCol = 35;
            break;
        case 1:
            startRow = 2;
            startCol = 35;

            questionCol = 35;
            questionRow = 12;

            promptCol = 35;
            promptRow = 30;

            answerCol = 35;
            answerRow = 7;

            booksRow = 9;
            booksCol = 35;

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
string GFPlayer::rankToString(Rank ra) {
    string r;
    switch (ra) {
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
            r = "";
            break;
    }
    return r;
}
void GFPlayer::makeBooks() {
    // TODO: In this function, sort the cards in the hand of the player for greater efficiency.
    char rankChar;
    int i, j, counter,loopCounter;
    for (i = TWO; i <= ACE; i = Rank(i + 1)) {
        counter = 0;
        for (j = 0; j < hand.size(); j++) {
            if (hand.at(j).rank == Rank(i)) {
                counter++;
            }
        }

        if (counter == 4) {
            loopCounter = 4;
            books.push_back(rankToString(Rank(i)));
            while(loopCounter > 0) {
                for (j = 0; j < hand.size(); j++) {
                    if (hand.at(j).rank == Rank(i)) {
                        removeCard(j);
                        break;
                    }
                }
                loopCounter--;
            }
        }
    }
}
void GFPlayer::renderBooks() {
    int i;
    string allbooks = "Books: ";
    for (i = 0; i < books.size(); i++) {
        allbooks.append(books.at(i));
        allbooks.append("  ");
    }
    char allbooksCopy[1024];
    strcpy(allbooksCopy, allbooks.c_str());
    // cout << "Player No: " << playerNumber << "\n\r";
    if(0 == playerNumber) {
        mvaddstr(32, 35, allbooksCopy);
    } else {
        mvaddstr(9, 35, allbooksCopy);
    }
}