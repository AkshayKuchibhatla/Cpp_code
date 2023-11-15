#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include "Hangman.h"
using namespace std;

Hangman aHangman;
TEST_CASE ("Does constructor start off at the first stage of hangman?") {
    CHECK(aHangman.stage == EMPTY);
    printf("Bing chilling");
}
