#include <iostream>
using namespace std;

struct Time {
    int hours, minutes;
    double seconds;
};

void increment(Time& time, double secs) {
    time.seconds += secs;
    int x;

    if (secs >= 3600) {
        x = int(time.seconds / 3600);
        time.hours += x;
        time.seconds -= x * 3600;
    }

    if (secs >= 60) {
        x = int(time.seconds / 60);
        time.minutes += x;
        time.seconds -= x * 60;
    }
}

int main() {

    return 0;
}