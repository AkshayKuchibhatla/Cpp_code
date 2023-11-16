#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include "Snowman.h"
using namespace std;

Snowman aSnowman;
TEST_CASE ("Does constructor start off at the first stage of hangman?") {
    CHECK(aSnowman.stage == MELTED);
}
