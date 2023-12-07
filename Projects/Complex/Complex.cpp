#include <iostream>
#include <math.h>
#include <string>
#include "Complex.hpp"
using namespace std;

//========CARTESIAN SUBCLASS METHODS===================================
// Constructors
Cartesian::Cartesian() {
    this->real = 0;
    this->imaginary = 0;
}
Cartesian::Cartesian(double r, double i) {
    this->real = r;
    this->imaginary = i;
}
Cartesian::Cartesian(Polar p) {
    this->real = p.getMagnitude() * cos(p.getTheta());
    this->imaginary = p.getMagnitude() * sin(p.getTheta());
}

// Public interface
double Cartesian::getReal() {
    return this->real;
}
double Cartesian::getImaginary() {
    return this->imaginary;
}
double Cartesian::abs() {
    return pow(pow(this->real,2) + pow(this->imaginary, 2), 0.5);
}

// Operator overload
Cartesian Cartesian::operator + (Cartesian c) {
   Cartesian comp = Cartesian(this->getReal() + c.getReal(), this->getImaginary() + c.getImaginary());
    return comp;
}
Cartesian Cartesian::operator - (Cartesian c) {
    Cartesian comp = Cartesian(this->getReal() - c.getReal(), this->getImaginary() - c.getImaginary());
    return comp;
}
Cartesian Cartesian::operator * (Cartesian c) {
    return Cartesian(Polar(*this) * Polar(c));
}
Cartesian Cartesian::operator / (Cartesian c) {
    return Cartesian(Polar(*this) / Polar(c));
}

std::string Cartesian::to_string() {
    return std::to_string(this->getReal()) + " + " 
    + std::to_string(this->getImaginary()) + "i";
}

//========POLAR SUBCLASS METHODS======================================
// Constructors
Polar::Polar() {
    this->theta = 0;
    this->magnitude = 0;
}
Polar::Polar(double m, double t) {
    this->magnitude = m;
    this->theta = t;
}
Polar::Polar(Cartesian c) {
    this->magnitude = pow(pow(c.getReal(), 2) 
    + pow(c.getImaginary(), 2), 0.5);
    this->theta = atan(c.getImaginary()/c.getReal());
}

// Public interface
double Polar::getMagnitude() {
    return this->magnitude;
}
double Polar::getTheta() {
    return this->theta;
}
double Polar::abs() {
    return this->magnitude;
}

// Operator overloading
Polar Polar::operator + (Polar p) {
    return Polar(Cartesian(*this) + Cartesian(p));
}
Polar Polar::operator - (Polar p) {
    return Polar(Cartesian(*this) - Cartesian(p));
}
Polar Polar::operator * (Polar p) {
    return Polar(this->magnitude * p.magnitude, this->theta + p.theta);
}
Polar Polar::operator / (Polar p) {
    return Polar(this->magnitude / p.magnitude, this->theta - p.theta);
}

std::string Polar::to_string() {
    return std::to_string(this->getMagnitude())  + "e^" 
    + std::to_string(this->getTheta()) + "i";
}