#include <iostream>
#include "Fraction.h"
using namespace std;

// Constructors:
Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction::Fraction() {
    this->numerator = 0;
    this->denominator = 1;
}



// Mathematical operations (modifiers):
void Fraction::add(Fraction frac) {
    // First, find the LCM of the denominators:
    int lcm = LCM(this->denominator, frac.denominator);

    // Second, add the proportionate numerators together:
    this->numerator = this->numerator * lcm/this->denominator 
    + frac.numerator * lcm/frac.denominator;
    
    // Third, set the denominator to the LCM:
    this->denominator = lcm;

    // Lastly, simplify:
    this->simplify();
}
void Fraction::subtract(Fraction frac) {
    // First, find the LCM of the denominators:
    int lcm = LCM(this->denominator, frac.denominator);

    // Second, subtract the proportionate numerators:
    this->numerator = this->numerator * lcm/this->denominator 
    + frac.numerator * lcm/frac.denominator;
    
    // Third, set the denominator to the LCM:
    this->denominator = lcm;

    // Lastly, simplify:
    this->simplify();
}
void Fraction::multiply(Fraction frac) {
    // Multiply the numerators and denominators:
    this->numerator *= frac.numerator;
    this->denominator *= frac.denominator;
    this->simplify();
}
void Fraction::divide(Fraction frac) {
    // Multiply by the reciprocal:
    this->numerator *= frac.denominator;
    this->denominator *= frac.numerator;
    this->simplify();
}
void Fraction::simplify() {
    // Divide by the greatest common factor to simplify:
    int gcf = GCF(this->denominator, this->numerator);
    this->numerator = numerator / gcf;
    this->denominator = denominator / gcf;
}



// Pure functions:
// Getting the GCF through Euclid's algorithm:
int Fraction::GCF(int number1, int number2) {
    if (number2 > number1) {
        return GCF(number2, number1);
    }

    if (number2 == 0) {
        return number1;
    } else {
        return GCF(number2, number1 % number2);
    }
}
// Getting the LCM through the GCF:
int Fraction::LCM(int number1, int number2) {
    return abs(number1 * number2 / GCF(number1, number2));
}
// Printing the fraction:
void Fraction::print() {
    cout << this->numerator << "/" << this->denominator;
}
std::string Fraction::to_string() {
    if (this->denominator == 1) {
        return std::to_string(this->numerator);
    }
    return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
}