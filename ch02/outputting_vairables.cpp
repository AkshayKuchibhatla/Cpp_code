#include <iostream>
using namespace std;

int main() {
    int hour, minute;
    char colon;

    hour = 11;
    minute = 59;
    colon = ':';

    cout << "The current time is ";
    cout << hour;
    cout << colon;
    cout << minute;
    cout << endl;
    return 0;
}