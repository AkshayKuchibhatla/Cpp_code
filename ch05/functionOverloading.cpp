#include <iostream>
using namespace std;

/* getSequence() is a function that adds all
the integers */
int getSequence() { // Overload #1
    return 1;
}

int getSequence(unsigned int upperNumber) { // Overload #2
    if (upperNumber == 1) {
        return upperNumber;
    } else {
        return upperNumber + getSequence(upperNumber - 1);
    }
}

int getSequence(unsigned int lowerNumber, unsigned int upperNumber) { // Overload #3
    if (upperNumber == lowerNumber) {
        return upperNumber;
    } else {
        return upperNumber + getSequence(lowerNumber, upperNumber - 1);
    }
}

int getSequence(unsigned int lowerNumber, unsigned int upperNumber, unsigned int increment) { // Overload #4
    if (upperNumber < lowerNumber) {
        return lowerNumber;
    } else {
        return upperNumber + getSequence(lowerNumber, upperNumber - increment, increment);
    }
}

int getSequence(unsigned int lowerNumber, unsigned int upperNumber, unsigned int increment, bool loading) { // Overload #5
    if (upperNumber < lowerNumber) {
        return upperNumber;
    } else {
        if (loading) {
            cout << '.';
        }
        return upperNumber + getSequence(lowerNumber, upperNumber - increment, increment);
    }
}

int main() {
    cout << endl;
    cout << getSequence();
    cout << endl;
    cout << getSequence(5);
    cout << endl;
    cout << getSequence(5,20);
    cout << endl;
    cout << getSequence(9,30,10);
    cout << endl;
    cout << getSequence(2, 100, 4);
    cout << endl;
}