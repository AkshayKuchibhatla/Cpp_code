#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "GoFish.h"
#include "GFPlayer.h"
#include "Card.h"
using namespace std;

// ================== GAME OBJECT ============================

// Default constructor simply creates a game with two players.
GoFish::GoFish() {
    GoFish(2);
}
GoFish::GoFish(int numberOfPlayers) {
    this->fishPile.shuffle(); // Shuffle the deck.

    int cardsPerPlayer = (numberOfPlayers > 2) ? 5 : 7; // If there are 3 or 4 players, each player starts with 5 cards. Otherwise, 7.
    cout << "Number of players: " << numberOfPlayers << "\n\r";
    cout << "Cards per player: " << cardsPerPlayer << "\n\r";
    int i,j;

    for (i = 0; i < numberOfPlayers; i++) {
        this->playerList.push_back(GFPlayer(i)); // Create new players
    }
    
    for (i = 0; i < cardsPerPlayer; i++) {
        for (j = 0; j < numberOfPlayers; j++) {
            dealCard(j); // Deal cards to each player.
        }
    }
    playerList[0].showHand();
    playerList[1].showHand();
    playerList[0].renderHand();
    playerList[1].renderHand();

    startGame();
}
void GoFish::startGame() {
    char x;
    currentPlayer = 0;
    
    while (!gameOver()) {
        x = askCard(currentPlayer);
        bool given = giveCards(currentPlayer, getNextPlayer(), x);
        cout << given << "\n\r";
        
        givenMessage(given);
        refreshScreen();
    }
}
void GoFish::refreshScreen() {
    clear();
    refresh();
    playerList[0].renderHand();
    playerList[1].renderHand();
    refresh();
    usleep(1500000);
}
void GoFish::givenMessage(bool param) {
        if (!param) {
        printGoFishMsg(getNextPlayer());
        dealCard(currentPlayer);
        currentPlayer = getNextPlayer();
    } else {
        printYesMsg(getNextPlayer());
    }
    refresh();
    usleep(2000000);
}

Deck GoFish::getFishPile() {
    return this->fishPile;
}
// @param playerNumber: The player to which to deal a card.
void GoFish::dealCard(int playerNumber) {
    this->playerList.at(playerNumber).addCard(this->fishPile.drawCard());
}
void GoFish::nextTurn() {
    if (++currentPlayer == playerList.size()) {
        currentPlayer = 0;
    }
}
bool GoFish::gameOver() {
    int booksMade = 0;
    for (int e = 0; e < playerList.size(); e++) {
        booksMade += playerList.at(e).getBooks().size();
    }
    if (booksMade == 13) return true;

    return false;
}
int GoFish::getNextPlayer() {
    if (currentPlayer == 0) return 1;
    return 0;
}
char GoFish::askCard(int player) {
    if (player == 1) {
        
    }
    int ch;
    mvaddstr(playerList.at(player).promptRow, playerList.at(player).promptCol, "Enter a card rank: ");
    ch = getch();
    string questionRoot = "Do you have any ";
    questionRoot.append(string(1, ch));
    questionRoot.append("'s?");
    char questionCopy[1024];
    strcpy(questionCopy, questionRoot.c_str());
    mvaddstr(playerList.at(player).questionRow, playerList.at(player).questionCol, questionCopy);
    return ch;
}
void GoFish::printGoFishMsg(int answeringPlayer) {
    mvaddstr(playerList.at(answeringPlayer).answerRow, playerList.at(answeringPlayer).answerCol, "GO FISH!");
}
void GoFish::printYesMsg(int answeringPlayer) {
    mvaddstr(playerList.at(answeringPlayer).answerRow, playerList.at(answeringPlayer).answerCol, "Yes!");
}
bool GoFish::giveCards(int askingPlayer, int answeringPlayer, char rank) {
    Rank rankToSearchFor;
    vector<Card> cardsToBeGiven;
    int i;
    
    switch (rank) {
    case '2':
        rankToSearchFor = TWO;
        break;
    case '3':
        rankToSearchFor = THREE;
        break;
    case '4':
        rankToSearchFor = FOUR;
        break;
    case '5':
        rankToSearchFor = FIVE;
        break;
    case '6':
        rankToSearchFor = SIX;
        break;
    case '7':
        rankToSearchFor = SEVEN;
        break;
    case '8':
        rankToSearchFor = EIGHT;
        break;
    case '9':
        rankToSearchFor = NINE;
        break;
    case '1':
        rankToSearchFor = TEN;
        break;
    case 'j':
        rankToSearchFor = JACK;
        break;
    case 'q':
        rankToSearchFor = QUEEN;
        break;
    case 'k':
        rankToSearchFor = KING;
        break;
    case 'a':
        rankToSearchFor = ACE;
        break;
    default:
        rankToSearchFor = TWO;
        break;
    }

    for (i = 0; i < playerList.at(answeringPlayer).getHand().size(); i++) {
        
        if (playerList.at(answeringPlayer).getHand().at(i).rank == rankToSearchFor) {
            cardsToBeGiven.push_back(playerList.at(answeringPlayer).getHand().at(i));
            playerList.at(answeringPlayer).removeCard(i);
        }
    }
    if (cardsToBeGiven.size() == 0) return false;

    for (i = 0; i < cardsToBeGiven.size(); i++) {
        cout << cardsToBeGiven.at(i).to_string() << "\n\r";
        playerList.at(askingPlayer).addCard(cardsToBeGiven.at(i));
    }

    return true;
}