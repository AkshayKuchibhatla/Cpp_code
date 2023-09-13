#include <iostream>
#include <cmath>
using namespace std;

/* This distance function finds the distance
between two hypothetical points on the coordinate 
plane:*/
double distance(double x1, double x2, double y1, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
    cout << endl;
    int xOne;
    int xTwo;
    int yOne;
    int yTwo;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        xOne = rand() % 11;
        xTwo = rand() % 11;
        yOne = rand() % 11;
        yTwo = rand() % 11;
        cout << "The distance between (" 
        << xOne << ", " << yOne
        << ") and "
        << "(" << xTwo << ", " << yTwo
        << ") is "
        << distance(xOne, xTwo, yOne, yTwo)
        << endl;
    }
    cout << endl;
    return 0;
}