#pragma once
#include <vector>
#include <string>
#include "Card.h"
#include "GFPlayer.h"
using namespace std;

// This header file defines all the elements of the game
class GoFish { // Singleton class that controls the flow of gameplay.
    int currentPlayer; // Which player's turn is it?
    Deck fishPile; // The pile of cards in the center
    vector<GFPlayer> playerList; // List of the players in the game.
    static GoFish* instance;
    public:
        // Default constructor
        GoFish();
        // Game accepts only 2 players for now.
        // TODO: implement more than one players.
        GoFish(int numberOfPlayers);
        // Constructor for dummy object to conduct tests
        GoFish(bool testing);
        // Returns the fishpile
        Deck getFishPile();
        // Deals a random card to a player.
        void dealCard(int playerNumber);
        // Starts the game.
        void startGame();
        // Advances the current player.
        void nextTurn();
        // Checks if the game is over.
        bool gameOver();
        // Returns the number of the next player.
        int getNextPlayer();
        // Enacts the ask function for the player whose turn it is.
        char askCard(int player);
        // Transfers cards from one player's hand to another.
        bool giveCards(int askingPlayer, int answeringPlayer, char rank);
        // Prints the message go fish when needed.
        void printGoFishMsg(int answeringPlayer);
        // Prints yes when cards are present in answering hand.
        void printYesMsg(int answeringPlayer);
        void givenMessage(bool param);
        // Refreshes the screen and rerenders the hands of the players.
        void refreshScreen();
        // Converts rank enum into a single character.
        char rankToChar(Rank r);
        // Returns the player list
        vector<GFPlayer> getPlayerList();
};