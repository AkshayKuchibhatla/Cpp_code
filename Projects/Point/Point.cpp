#include <iostream>
#include <string>
#include <math.h>
#include "Point.hpp"
using namespace std;

Point::Point() {
    this->x = 0;
    this->y = 0;
}
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point Point::operator + (Point p) {
    return Point(this->x + p.x, this->y + p.y);
}
Point Point::operator - (Point p) {
    return Point(this->x - p.x, this->y - p.y);
}
ostream& operator << (ostream& os, Point& p) {
    os << p.to_string();
    return os;
}
Point Point::operator * (Point p) {
    return Point(this->x * p.x, this->y * p.y);
}
Point operator * (int i, Point p) {
    return Point(p.getX() * i, p.getY() * i);
}

// Public interface
double Point::getX() {
    return this->x;
}
double Point::getY() {
    return this->y;
}

// Other
double Point::distance(Point p) {
    return pow(pow(this->x - p.x, 2) + pow(this->y - p.y, 2), 0.5);
}

// to_string()
std::string Point::to_string() {
    return "(" + std::to_string(this->x) + ", " 
    + std::to_string(this->y) + ")";
}