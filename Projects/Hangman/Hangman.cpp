#include <iostream>
#include <fstream>
#include <vector>
#include "Hangman.h"
using namespace std;

Hangman::Hangman() {
    this->stage = EMPTY;
}

void Hangman::setStage(Stage stage) {
    this->stage = stage;
}
void Hangman::render() {
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
}