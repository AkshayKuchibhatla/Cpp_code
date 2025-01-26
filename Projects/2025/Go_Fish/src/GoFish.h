#ifndef GOFISH_H
#define GOFISH_H
#endif

#include <vector>
#include <ncurses.h>
#include "Card.h"
using namespace std;
// This header file defines all the elements of the game

class GFPlayer { // Object describing a player and their actions
    Deck hand; // The player's hand.
    Deck books; // Stores one card from each book (four of a kind set) that the player has.
    bool handFaceUp; // Tells whether the cards in the player's hand are face up or not.
    
    void renderHand();
    void renderBooks();
};

class GoFish { // Singleton class that controls the flow of gameplay.
    int playersTurn; // Which player's turn is it?
    Deck fishPile; // The pile of cards in the center
    vector<GFPlayer> playerList; // List of the players in the game.
    public:
        // Default constructor
        GoFish();
        // Game accepts 2 to 4 players
        GoFish(int numberOfPlayers);
};