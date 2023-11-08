#include <iostream>
#include "Hangman.h"
using namespace std;

int main() {
    Hangman hangman;
    char letter;
    
    while (hangman.stage != BOTH_LEGS) {
        hangman.render();
        cout << "Guess a letter: ";
        cin >> letter;

        if (hangman.hasLetter(letter)) {
            hangman.replaceLetters(letter);
            if (hangman.userGuess == hangman.word) {
                cout << "\n\n" << "Good job. You have successfully guessed the word.";
                return 0;
            }
        } else {
            hangman.nextStage();
        }
    }
    hangman.render();
    cout << "\n\n" << "The word was " << hangman.word << ".";
    return 0;
}