#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include "Snowman.h"
using namespace std;

TEST_CASE ("Does constructor start off at the first stage of hangman?") {
    Snowman aSnowman;
    CHECK(aSnowman.stage == FULL);
}

TEST_CASE ("Does hasLetter() work?") {
    Snowman aSnowman("aligator");
    CHECK(aSnowman.hasLetter('a'));
}

TEST_CASE ("Does replaceLetter() work?") {
    Snowman aSnowman("Mississippi");
    aSnowman.replaceLetters('s');
    CHECK(aSnowman.userGuess == "__ss_ss____");
}

TEST_CASE ("Does nextStage() work?") {
    Snowman aSnowman;
    aSnowman.nextStage();
    CHECK(aSnowman.stage == NO_HAT);
}

TEST_CASE ("Does setStage() work?") {
    Snowman aSnowman;
    aSnowman.setStage(NO_BASE);
    CHECK(aSnowman.stage == NO_BASE);
}