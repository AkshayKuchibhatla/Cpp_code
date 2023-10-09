#include <iostream>
#include <cstring>
using namespace std;

int str_len(char x[]) {
    char* charPointer = x;
    int length = 0;
    while (true) {
        try {
            length++;
            charPointer++;
            cout << *charPointer << endl;
            throw length;
        } catch (int length) {
            return length;
        }
    }
}

int main() {
    char thing[] = "";
    cout << "Enter a string... ";
    cin >> thing;
    cout << str_len(thing);
    
    return 0;
}