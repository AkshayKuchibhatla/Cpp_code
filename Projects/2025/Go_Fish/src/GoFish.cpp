#include <iostream>
#include "GoFish.h"
#include "GFPlayer.h"
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
        cout << "\n\r" << "Iteration: " << i << "\n\r";
        for (j = 0; j < numberOfPlayers; j++) {
            dealCard(j); // Deal cards to each player.
        }
        playerList.at(1).printHand();
    }
    playerList[0].showHand();
    playerList[1].showHand();
    playerList[0].renderHand();
    playerList[1].renderHand();

    
}
Deck GoFish::getFishPile() {
    return this->fishPile;
}
// @param playerNumber: The player to which to deal a card.
void GoFish::dealCard(int playerNumber) {
    this->playerList.at(playerNumber).addCard(this->fishPile.drawCard());
}