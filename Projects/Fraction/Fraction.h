#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    // First, constructors:
    Fraction();
    Fraction(int numerator, int denominator);

    // These are all modifier functions:
    void add(Fraction frac);
    void subtract(Fraction frac);
    void multiply(Fraction frac);
    void divide(Fraction frac);
    void simplify();

    // These are some pure functions:
    int LCM(int number1, int number2);
    int GCF(int number1, int number2);

    // ...and you can't forget print:
    void print();
};