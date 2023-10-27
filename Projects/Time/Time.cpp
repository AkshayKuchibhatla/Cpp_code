#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

string daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// Pure functions
bool Time::after(Time pTime) {
    bool result;
    if (pTime.dayOfWeek > this->dayOfWeek) {return true;}
    if (pTime.dayOfWeek < this->dayOfWeek) {return false;}

    if (pTime.hours > this->hours) {return true;}
    if (pTime.hours < this->hours) {return false;}

    if (pTime.minutes > this->minutes) {return true;}
    if (pTime.minutes < this->minutes) {return false;}
    
    return (pTime.seconds > this->seconds);
}
double Time::convertToSeconds() const {
    int hour = this->hours + this->dayOfWeek * 24;
    int minute = this->minutes + hour * 60;
    double second = this->seconds + minute * 60;
    return second;
}
Time Time::add(Time t2) {
    return Time(this->convertToSeconds() + t2.convertToSeconds());
}
string Time::time_to_string() {
    return daysOfWeek[this->dayOfWeek] + ", " + to_string(this->hours) + ":" + to_string(this->minutes) + ":" + to_string(this->seconds);
}


// Modifiers
void Time::increment(double secs) {
    this->dayOfWeek += int(secs / 86400);
    secs -= this->dayOfWeek * 86400;
    this->hours += int(secs / 3600);
    secs -= this->hours * 60;
    this->minutes += int(secs / 60);
    secs -= this->minutes * 60;
    this->seconds += secs;
}


// Constructors
Time::Time(double secs) {
    this->dayOfWeek = int(secs / 86400);
    secs -= this->dayOfWeek * 86400;
    this->hours = int(secs / 3600);
    secs -= this->hours * 3600;
    this->minutes = int(secs / 60);
    secs -= this->minutes * 60;
    this->seconds = secs;
}
Time::Time(int d, int h, int m, double s) {
    this->dayOfWeek = d;
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}
Time::Time() {
    this->dayOfWeek = 0;
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}