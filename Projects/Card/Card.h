struct Card {
    int rank, suit;

    // Constructors
    Card();
    Card(int r, int s);

    // Pure functions
    string to_string();
    bool equals(Card c2);
};