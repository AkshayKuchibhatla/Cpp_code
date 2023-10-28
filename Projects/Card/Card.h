struct Card {
    int rank, suit;

    // Constructors
    Card();
    Card(int r, int s);

    // Pure functions
    std::string to_string();
    bool equals(Card card);
    bool isGreaterThan(Card card);
};