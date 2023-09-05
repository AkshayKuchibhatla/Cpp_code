#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    double randomNumber;
    double secondNumber;

    for (int i = 0; i < 5; i++) {
        randomNumber = rand();
        secondNumber = rand();
        cout << randomNumber << " * " << secondNumber << " = " << randomNumber * secondNumber;
        cout << "\n";
        cout << "\n";
    }

    for (int i = 0; i < 5; i++) {
        randomNumber = rand();
        secondNumber = rand();
        cout << randomNumber << " / " << secondNumber << " = " << randomNumber / secondNumber;
        cout << "\n";
        cout << "\n";
    }
    
    return 0;
}