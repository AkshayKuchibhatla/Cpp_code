#include <iostream>
#include "Random.h"
using namespace std;

int Random::randomNumberBetween(int low, int high) {
    if (low == high) {
        return low;
    }
    if (low > high) {
        return randomNumberBetween(high, low);
    }
    
    srand(time(NULL));
    return rand() % (high - low + 1) + low;
}