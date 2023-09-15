#include <iostream>
using namespace std;

void countdown(int n) {
    while (n > 0) {
        cout << n << endl;
        n = n - 1;
    }
    cout << "Blastoff!" << endl;
}

int main() {
    cout << endl;
    countdown(10); //Countdown from 10
    cout << endl;
    countdown(20); // Countdown from 20
    cout << endl;
    countdown(-1); // -1 is already less than 0, so the countdown wouldn't happen.
    cout << endl;
    return 0;
}