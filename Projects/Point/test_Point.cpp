#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "Point.hpp"
#include <string>
#include <doctest.h>
using namespace std;

TEST_CASE ("Point(x, y) works") {
    Point x = Point(3, 4);
    cout << x << endl;
    CHECK(x.getX() == 3.0);
    CHECK(x.getY() == 4.0);
}

TEST_CASE ("Point to_string() works") {
    Point x = Point();
    cout << x << endl;
    CHECK(x.getX() == 0.0);
    CHECK(x.getY() == 0.0);
}

TEST_CASE ("Point adding works") {
    Point x = Point(5,4);
    Point y = Point(1,3);
    Point z = x + y;
    CHECK(z.getX() == 6.0);
    CHECK(z.getY() == 7.0);
}

TEST_CASE ("Point subtracting works") {
    Point x = Point(5,4);
    Point y = Point(1,3);
    Point z = x - y;
    CHECK(z.getX() == 4.0);
    CHECK(z.getY() == 1.0);
}

TEST_CASE ("Point distance works") {
    Point a = Point();
    Point b = Point (3,4);
    CHECK(a.distance(b) == 5.0);
}