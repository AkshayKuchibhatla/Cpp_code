struct Date {
    int day, month, year;

    // Pure functions
    std::string to_string();

    // Modifiers
    void increment(int days);
};