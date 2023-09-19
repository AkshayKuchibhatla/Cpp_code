#include <iostream>
using namespace std;

void printNames() {
    char uChar = 'u';
    string suffix = "ack";
    char letter = 'J';
    while (letter < 'R') {
        if (letter == 'Q' || letter == 'O') {
            cout << letter << uChar << suffix << endl;
        } else {
            cout << letter + suffix << endl;
        }
        letter++;
    }
}

int main() {
    printNames();
    return 0;
}