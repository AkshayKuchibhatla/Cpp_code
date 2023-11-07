#include <iostream>
#include "Hangman.h"
using namespace std;

int main() {
    Hangman hangman;
    string word = words[rand() % 225];
    
    for (int i = 1; i <= 7; i++) {
        hangman.setStage(Stage(i*7));
        hangman.render();
    }
    return 0;
}