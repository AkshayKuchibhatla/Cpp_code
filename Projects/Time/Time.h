struct Time { 
    /* This sturcture includes the day of the week, so 
    it gauges how far someone is into the week.*/
    double seconds;
    int dayOfWeek, hours, minutes;

    // Modifiers
    void increment(double parameterSeconds);

    // Functions
    void printTime();
    bool after(Time pTime);
    double convertToSeconds() const;
    Time add(Time t2);
    std::string time_to_string();

    // Constructors
    Time();
    Time(double seconds);
    Time(int d, int h, int m, double s);
};