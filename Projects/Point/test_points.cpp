#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Point.hpp"
using namespace std;

TEST_CASE("Test can create and render a Point") {
    Point p;
    CHECK(p.to_string() == "(0, 0)");
    Point p2(2,3);
    CHECK(p2.to_string() == "(2, 3)");
}

TEST_CASE("Test can add Points with +") {
    Point p1(2,3);
    Point p2(4,7);
    Point p3 = p1 + p2; 
    CHECK(p3.to_string() == "(6, 10)");
}

TEST_CASE("Test can subtract Point with -") {
    Point p1(2,3);
    Point p2(4,7);
    Point p3 = p1 - p2; 
    CHECK(p3.to_string() == "(-2, -4)");
}

TEST_CASE("Test can multiply Point by a scalar with *") {
    Point p(3,4);
    Point p2 = 2 * p;
    CHECK(p2.to_string() == "(6, 8)");
}

TEST_CASE("Test can find distance between two Points") {
    Point p1(3,0);
    Point p2(0,4);
    CHECK(p1.distance(p2) == 5.000000);
}
