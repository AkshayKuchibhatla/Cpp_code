#include <iostream>
#include <fstream>
#include <vector>
#include "Hangman.h"
using namespace std;

Hangman::Hangman() {
    srand(time(NULL));
    this->word = words[rand() % 240];
    this->userGuess = "";
    for (int i = 0; i < this->word.length(); i++) {
        userGuess += "_";
    }
    this->stage = EMPTY;
}

void Hangman::setStage(Stage stage) {
    this->stage = stage;
}
void Hangman::nextStage() {
    this->setStage(Stage(this->stage + 7));
}
void Hangman::render() { // This is basically to_string().
    ifstream readFile("Hangman.txt");
    vector<string> lines;
    lines.push_back("");/*Assign an empty value 
    to the 0th index so mapping indexes is easy.*/
    string line;
    while (getline(readFile,line)) {
        lines.push_back(line);
    }
    
    for (int i = this->stage - 6; i <= this->stage; i++) {
        cout << lines[i] << endl;
    }
    cout << this->userGuess << "\n\n";
}
void Hangman::replaceLetters(char letter) {
    for (int i = 0; i < this->word.length(); i++) {
        if (letter == this->word[i]) {
            userGuess[i] = letter;
        }
    }
}

bool Hangman::hasLetter(char letter) {
    for (int i = 0; i < this->word.length(); i++) {
        if (letter == this->word[i]) {
            return true;
        }
    }
    return false;
}