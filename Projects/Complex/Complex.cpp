#include <iostream>
#include "Complex.hpp"
using namespace std;

int main() {
    Complex itsComplicated = Complex(3,4);
    // itsComplicated.calculateCartesian();
    itsComplicated.calculatePolar();

    cout << itsComplicated.cartesian_to_string() << endl;
    cout << itsComplicated.polar_to_string() << endl;
    return 0;
}