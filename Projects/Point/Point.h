class Point {
    double x, y;

    public:
        // Constructors
        Point();
        Point(double x, double y);

        // operator overloads
        Point operator + (Point p);
        Point operator - (Point p);
        Point operator * (Point p);

        // Public interface
        double getX();
        double getY();

        // Other
        double distance(Point p);

        // to_string()
        // std::string to_string();
        // friend std::ostream& operator << (std::ostream& os, Point& c);
};

Point operator * (int i, Point p);