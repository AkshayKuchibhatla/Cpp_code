#include <iostream>
#include "Snowman.h"
using namespace std;

int main() {
    Snowman snowman;
    char letter;

    while (snowman.stage != MELTED) {
        snowman.render();
        cout << "Guess a letter: ";
        cin >> letter;

        if (snowman.hasLetter(letter)) {
            snowman.replaceLetters(letter);
            if (snowman.userGuess == snowman.word) {
                cout << "\n\n" << snowman.userGuess << "\n\n" << "Good job. You have successfully guessed the word.";
                return 0;
            }
        } else {
            snowman.nextStage();
        }
    }
    snowman.render();
    cout << "\n\n" << "The word was " << snowman.word << ".";
    return 0;
}