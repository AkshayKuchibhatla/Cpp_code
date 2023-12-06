#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "Complex.hpp"
#include <doctest.h>
using namespace std;

TEST_CASE("Complex objects can be added with +") {
    Complex x(3,4);
    Complex y(4,5);
    Complex z = x + y;
    CHECK(z.getReal() == 7.0);
    CHECK(z.getImaginary() == 9.0);
}