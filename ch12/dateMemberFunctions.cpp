#include <iostream>
#include <cmath>
using namespace std;

struct Date {
    int day, month, year;
    void print();
    void increment(int days);
};

void Date::print() {
    cout << month << "/" << day << "/" << year;
}

void Date::increment(int days) {
    day += days;
    
}

int main() {
    return 0;
}