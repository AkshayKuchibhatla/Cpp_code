#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    Time x(0, 10, 10, 10);
    cout << x.convertToSeconds() << endl;
    cout << x.time_to_string();
    x.increment(86400);
    cout << x.time_to_string();

    return 0;
}