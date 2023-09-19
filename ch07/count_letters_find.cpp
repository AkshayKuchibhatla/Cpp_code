#include <iostream>
#include <string>
using namespace std;

int countLetters(string p_string, char p_char) {
    int place = p_string.find(p_char);
    return place;
}

int main() {
    string text;
    char letter;
    cout << "Enter a string... ";
    cin >> text;
    cout << "Enter a character... ";
    cin >> letter;

    cout << countLetters(text, letter);

    return 0;
}