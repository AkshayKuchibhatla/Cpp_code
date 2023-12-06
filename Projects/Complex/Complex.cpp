#include <iostream>
#include "Complex.hpp"
using namespace std;

Complex::Complex() {
    this->real = 0; 
    this->imaginary = 0;
    this->polar = false;
}
Complex::Complex(double r, double i) {
    this->real = r; this->imaginary = i;
    this->polar = false;
}
Complex::Complex(double m, double t, Flag) {
    this->magnitude = m;
    this->theta = t;
    this->polar = true;

}

// Accessor functions
double Complex::getReal() {
    return this->real;
}
double Complex::getImaginary() {
    return this->imaginary;
}
double Complex::getMagnitude() {
    if (!this->polar) this->calculatePolar();
    return this->magnitude;
}
double Complex::getTheta() {
    if (!this->polar) this->calculatePolar();
    return this->theta;
}
double Complex::abs() {
    return pow(pow(this->real,2) + pow(this->imaginary, 2), 0.5);
}
bool Complex::isPolar() {
    return this->polar;
}

// to_string() functions
std::string Complex::cartesian_to_string() {
    return std::to_string(this->getReal()) + " + " 
    + std::to_string(this->getImaginary()) + "i";
}
std::string Complex::polar_to_string() {
    std::string thet = std::to_string(this->getTheta());
    std::string mag = std::to_string(this->getMagnitude());
    return mag  + "e^" + thet + "i";
}

// Modifier functions
void Complex::calculatePolar() {
    this->magnitude = pow(pow(this->real, 2) 
    + pow(this->imaginary, 2), 0.5);
    this->theta = atan(this->imaginary/this->real);
    this->polar = true;
}
void Complex::calculateCartesian() {
    assert(polar == true);
    this->real = this->magnitude * cos(this->theta);
    this->imaginary = this->magnitude * sin(this->theta);
}

// Operator overloading
Complex Complex::operator + (Complex c) {
    Complex comp = Complex(this->getReal() + c.getReal(), this->getImaginary() + c.getImaginary());
    comp.calculatePolar();
    return comp;
}
Complex Complex::operator - (Complex c) {
    Complex comp = Complex(this->getReal() - c.getReal(), this->getImaginary() - c.getImaginary());
    comp.calculatePolar();
    return comp;
}
Complex Complex::operator * (Complex c) {
    if (this->polar == false) this->calculatePolar();
    if (c.polar == false) c.calculatePolar();
    return Complex(this->magnitude * c.magnitude, this->theta + c.theta, POLAR);
}
Complex Complex::operator / (Complex c) {
    if (this->polar == false) this->calculatePolar();
    if (c.polar == false) c.calculatePolar();
    return Complex(this->magnitude / c.magnitude, this->theta - c.theta, POLAR);
}
ostream& operator << (ostream& os, Complex& c) {
    if (c.isPolar()) {
        os << c.polar_to_string();
    } else {
        os << c.cartesian_to_string();
    }
    return os;
}