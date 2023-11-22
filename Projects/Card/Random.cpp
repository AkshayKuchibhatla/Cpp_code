#include <iostream>
#include "Random.h"
using namespace std;

int randomNumberBetween(int low, int high) {
    srand(time(NULL));
    return rand() % (high - low + 1) + low;
}