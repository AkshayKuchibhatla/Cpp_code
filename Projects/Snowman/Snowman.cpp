/*
Snowman Game
Authors: Akshay Kuchibhatla and Jackson Curtis
CSC222
A parody of the classic word-guessing game 
"hangman" where a snowman progressively 
melts while the user is trying to guess a
word.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Snowman.h"
using namespace std;

Snowman::Snowman() {
    srand(time(NULL));
    this->word = words[rand() % 240];
    this->userGuess = "";
    for (int i = 0; i < this->word.length(); i++) {
        this->userGuess += "_";
    }
    this->stage = FULL;
}
Snowman::Snowman(string aWord) {
    this->word = aWord;
    this->userGuess = "";
    for (int i = 0; i < this->word.length(); i++) {
        this->userGuess += "_";
    }
    this->stage = FULL;
}

void Snowman::setStage(Stage stage) {
    this->stage = stage;
}
void Snowman::nextStage() {
    this->setStage(Stage(this->stage + 6));
}
void Snowman::render() { // This is basically to_string().
    ifstream readFile("Snowman.txt");
    vector<string> lines;
    lines.push_back("");/*Assign an empty value 
    to the 0th index so mapping indexes is easy.*/
    string line;
    while (getline(readFile,line)) {
        lines.push_back(line);
    }
    
    for (int i = this->stage - 5; i <= this->stage; i++) {
        cout << lines[i] << endl;
    }
    cout << this->userGuess << "\n\n";
}
void Snowman::replaceLetters(char letter) {
    for (int i = 0; i < this->word.length(); i++) {
        if (letter == this->word[i]) {
            userGuess[i] = letter;
        }
    }
}

bool Snowman::hasLetter(char letter) {
    for (int i = 0; i < this->word.length(); i++) {
        if (letter == this->word[i]) {
            return true;
        }
    }
    return false;
}