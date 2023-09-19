#include <iostream>
#include <string>
using namespace std;

int countLetters(string p_string, char p_char) {
    int count = 0;
    int index = 0;

    while (index < p_string.length()) {
        if (p_string[index] == p_char) {
            count = count + 1;
        }
        index = index + 1;
    }
    return count;
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