#include <iostream>
#include "Fraction.h"
using namespace std;
/* Note: For this program to work, it needs to be compiled alongside 
Fraction.cpp like so: g++ Fraction.cpp FractionTest.cpp*/ 

int main() {
    int num1;
    int den1;
    int num2;
    int den2;
    char operation;
    cout << endl;
    cout << "Enter the numerator of Fraction #1: ";
    cin >> num1;
    cout << "Enter the denominator of Fraction #1: ";
    cin >> den1;
    cout << endl;
    cout << "Enter an operation: ";
    cin >> operation;
    cout << endl;
    cout << "Enter the numerator of Fraction #2: ";
    cin >> num2;
    cout << "Enter the denominator of Fraction #2: ";
    cin >> den2;
    cout << endl;

    Fraction fraction1(num1, den1);
    Fraction fraction2(num2, den2);
    
    fraction1.print();
    cout << " " << operation << " ";
    fraction2.print();
    cout << " = ";

    switch (operation) {
    case '+':
        fraction1.add(fraction2);
        break;
    case '-':
        fraction1.subtract(fraction2);
        break;
    case '*':
        fraction1.multiply(fraction2);
        break;
    case '/':
        fraction1.divide(fraction2);
    default:
        break;
    }

    fraction1.print();
    
    cout << endl;

    return 0;
}