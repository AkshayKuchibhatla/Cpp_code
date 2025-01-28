#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <iostream>
#include "GFPlayer.h"
#include "GoFish.h"



TEST_CASE("Testing the player object's attributes.") {
    GFPlayer p(0);
    CHECK(p.getHand().size() == 0); // Empty hand to start with
    CHECK(p.getBooks().size() == 0); // No sets collected to start with
    GoFish testGameObj(true);
    CHECK(testGameObj.getPlayerList().size() == 2);
    CHECK(testGameObj.getFishPile().cardsList.size() == 52);
    CHECK(testGameObj.getNextPlayer() == 1);
}