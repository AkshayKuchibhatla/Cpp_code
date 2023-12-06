#include <math.h>
#include <string>
#include <assert.h>

enum Flag {POLAR};

class Complex {
    double real, imaginary;
    double magnitude, theta;
    bool polar;

    public:
        // Constructors
        Complex();
        Complex(double r, double i);
        Complex(double m, double t, Flag);

        // Accessor functions
        double getReal();
        double getImaginary();
        double getMagnitude();
        double getTheta();
        double abs();
        bool isPolar();

        // to_string() functions
        std::string cartesian_to_string();
        std::string polar_to_string();

        // Modifier functions
        void calculatePolar();
        void calculateCartesian();

        // Operator overloading
        Complex operator + (Complex c);
        Complex operator - (Complex c);
        Complex operator * (Complex c);
        Complex operator / (Complex c);
        friend std::ostream& operator << (std::ostream& os, Complex& c);
};