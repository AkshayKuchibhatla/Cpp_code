#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

string daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

struct Time { 
    /* This sturcture includes the day of the week, so 
    it gauges how far someone is into the week.*/
    double seconds;
    int dayOfWeek, hours, minutes;
    Time(){};
    void printTime();
    bool after(Time pTime);
    double convertToSeconds(Time pTime) const;
    void increment(double parameterSeconds);
    Time(double seconds);
};


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

double Time::convertToSeconds(Time pTime) const {
    int hour = pTime.hours + pTime.dayOfWeek * 24;
    int minute = pTime.minutes + hour * 60;
    double second = pTime.seconds + minute * 60;
    return second;
}

void Time::increment(double parameterSeconds) {
    seconds += parameterSeconds;
    minutes += int(parameterSeconds / 60);
    seconds -= minutes * 60;
    hours += int(minutes / 60);
    minutes -= hours * 60;
    dayOfWeek += int(hours / 24);
    hours -= dayOfWeek * 24;
}

Time::Time(double parameterSeconds) {
    dayOfWeek = int(parameterSeconds / 86400);
    parameterSeconds -= dayOfWeek * 86400;
    hours = int(parameterSeconds / 3600);
    parameterSeconds -= hours * 3600;
    minutes = int(parameterSeconds / 60);
    parameterSeconds -= minutes * 60;
    seconds = parameterSeconds;
}



int main() {
    Time x(86400);
    // x.dayOfWeek = 1;
    // x.hours = 10;
    // x.minutes = 10;
    // x.seconds = 20.0;

    x.printTime();

    Time x1(86400);
    bool after = x.after(x1);
    cout << after << endl;

    return 0;
}