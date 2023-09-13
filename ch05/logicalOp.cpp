#include <iostream>
using namespace std;

void isWorkingAge(int age) {
    if (age > 16 && age < 65) {
        cout << "Your age is within the normal working age." << endl;
    } else {
        cout << "Your age is NOT within the normal working age." << endl;
    }
}

int main() {
    int ageInput;
    while (true) {
        cout << "Please enter your age: ";
        cin >> ageInput;
        isWorkingAge(ageInput);
        cout << endl;
    }
    return 0;
}