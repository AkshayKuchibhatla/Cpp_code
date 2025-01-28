#pragma once
#include "Card.h"
#include <vector>
#include <string>
using namespace std;

class GFPlayer { // Object describing a player and their actions
    vector<Card> hand; // The player's hand.
    vector<string> books; // Stores all the ranks of cards that the user has collected 4 each of.
    int playerNumber; // Helps with orientation of cards on the playing field.
    bool handFaceUp; // Tells whether the cards in the player's hand are face up or not.

    public:
        int startRow;
        int startCol;
        int questionRow;
        int questionCol;
        int promptRow;
        int promptCol;
        int answerRow;
        int answerCol;
        int booksRow;
        int booksCol;
        // Adds the specified card to the player's hand.
        // @param c: the card.
        void addCard(Card c);
        // Default constructor
        GFPlayer();
        // Player initialized with a number.
        GFPlayer(int number);
        // Player object renders player's hand, whether face up or face down.
        void renderHand();
        // Player object renders the full sets it has collected in the game so far.
        void renderBooks();
        // Player's hand goes face down.
        void hideHand();
        // Player's hand goes face up.
        void showHand();
        // Print the cards in the hand in string form to the console.
        void printHand();
        // Remove card at index in hand.
        void removeCard(int index);
        // Returns the player's hand.
        vector<Card> getHand();
        // Returns all the books that the player has made.
        vector<string> getBooks();
        // Makes all the sets of 4.
        void makeBooks();
        // Returns a string given a rank
        string rankToString(Rank ra);
};