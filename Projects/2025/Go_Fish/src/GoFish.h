#pragma once
#include <vector>
#include <string>
#include "Card.h"
#include "GFPlayer.h"
using namespace std;

// This header file defines all the elements of the game
class GoFish { // Singleton class that controls the flow of gameplay.
    int playersTurn; // Which player's turn is it?
    Deck fishPile; // The pile of cards in the center
    vector<GFPlayer> playerList; // List of the players in the game.
    static GoFish* instance;
    public:
        // Default constructor
        GoFish();
        // Game accepts 2 to 4 players
        GoFish(int numberOfPlayers);
        // Returns the fishpile
        Deck getFishPile();
        // Deals a random card to a player.
        void dealCard(int playerNumber);
};