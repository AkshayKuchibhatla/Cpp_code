#include <math.h>
#include <string>
#include <assert.h>

class Complex { 
    /* Abstract base class with no method implementations. 
    There are no attributes because those belong to the 
    sub classes. This is basically and interface if you
    speak java. */

    public:
        virtual ~Complex() = 0;

        // Accessor functions
        virtual double abs() = 0;

        // to_string
        virtual std::string to_string() = 0;
        
        // Print operator overload
        friend std::ostream& operator << (std::ostream& os, Complex& c);
};

class Cartesian : public Complex {
    double real, imaginary;

    public:
        // Constructors:
        Cartesian();
        Cartesian(double r, double i);
        Cartesian(Polar p); // For conversion

        // Public interface
        double getReal();
        double getImaginary();
        double abs() override;

        // Operator overloads
        Cartesian operator + (Cartesian c);
        Cartesian operator - (Cartesian c);
        Cartesian operator * (Cartesian c);
        Cartesian operator / (Cartesian c);

        // to_string() and <<
        std::string to_string() override;
};

class Polar: public Complex {
    double magnitude, theta;

    public:
        // Constructors:
        Polar();
        Polar(double m, double t);
        Polar(Cartesian c); // For conversion

        // Public interface
        double getMagnitude();
        double getTheta();
        double abs() override;

        // Operator overloads
        Polar operator + (Polar p);
        Polar operator - (Polar p);
        Polar operator * (Polar p);
        Polar operator / (Polar p);

        // to_string()
        std::string to_string() override;
        friend std::ostream& operator << (std::ostream& os, Polar& c);
};