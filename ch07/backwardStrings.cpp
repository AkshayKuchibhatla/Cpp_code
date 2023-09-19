#include <iostream>
#include <string>
using namespace std;

void stringBackwards(string input) {
    int size = input.length();
    for (int i = size - 1; i > -1; i--) {
        cout << input[i];
    }
}

int main() {
    string thing;
    cout << "Please enter a string... ";
    cin >> thing;
    cout << endl;
    stringBackwards(thing);
    return 0;
}