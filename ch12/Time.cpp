#include <iostream>
#include <cstring>
#include "Time.h"
using namespace std;

string daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

bool Time::after(Time pTime) {
    bool result;
    if (pTime.dayOfWeek > dayOfWeek) {return true;}
    if (pTime.dayOfWeek < dayOfWeek) {return false;}

    if (pTime.hours > hours) {return true;}
    if (pTime.hours < hours) {return false;}

    if (pTime.minutes > minutes) {return true;}
    if (pTime.minutes < minutes) {return false;}
    
    return (pTime.seconds > seconds);
}

void Time::printTime() {
    cout << daysOfWeek[dayOfWeek] << ", " << hours << ":" << minutes << ":" << seconds << endl;
}

double Time::convertToSeconds() const {
    int hour = hours + dayOfWeek * 24;
    int minute = minutes + hour * 60;
    double second = seconds + minute * 60;
    return second;
}

void Time::increment(double secs) {
    dayOfWeek += int(secs / 86400);
    secs -= dayOfWeek * 86400;
    hours += int(secs / 3600);
    secs -= hours * 60;
    minutes += int(secs / 60);
    secs -= minutes * 60;
    seconds += secs;
}

Time::Time(double secs) {
    dayOfWeek = int(secs / 86400);
    secs -= dayOfWeek * 86400;
    hours = int(secs / 3600);
    secs -= hours * 3600;
    minutes = int(secs / 60);
    secs -= minutes * 60;
    seconds = secs;
}

Time::Time(int d, int h, int m, double s) {
    dayOfWeek = d;
    hours = h;
    minutes = m;
    seconds = s;
}

Time Time::add(Time t2) {
    return Time(convertToSeconds() + t2.convertToSeconds());
}

int main() {
    Time x(0, 10, 10, 10);
    cout << x.convertToSeconds() << endl;
    x.printTime();
    x.increment(86400);
    x.printTime();

    return 0;
}