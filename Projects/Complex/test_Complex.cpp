#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "Complex.hpp"
#include <doctest.h>
using namespace std;

TEST_CASE("Complex objects can be added with +") {
    Cartesian x(3,4);
    Cartesian y(4,5);
    Cartesian z = x + y;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    CHECK(z.getReal() == 7.0);
    CHECK(z.getImaginary() == 9.0);
}