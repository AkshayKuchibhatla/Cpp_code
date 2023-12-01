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
        Complex() {
            this->real = 0; 
            this->imaginary = 0;
            this->polar = false;
        }
        Complex(double r, double i) {
            this->real = r; this->imaginary = i;
            this->polar = false;
        }
        Complex(double m, double t, Flag) {
            this->magnitude = m;
            this->theta = t;
            this->polar = true;

        }
        

        // Accessor functions
        double getReal() {
            return this->real;
        }
        double getImaginary() {
            return this->imaginary;
        }
        double getMagnitude() {
            if (!this->polar) this->calculatePolar();
            return this->magnitude;
        }
        double getTheta() {
            if (!this->polar) this->calculatePolar();
            return this->theta;
        }

        // to_string() functions
        std::string cartesian_to_string() {
            return std::to_string(this->getReal()) + " + " 
            + std::to_string(this->getImaginary()) + "i";
        }
        std::string polar_to_string() {
            std::string thet = std::to_string(this->getTheta());
            std::string mag = std::to_string(this->getMagnitude());
            return mag  + "e^" + thet + "i";
        }

        // Modifier functions
        void calculatePolar() {
            this->magnitude = pow(pow(this->real, 2) 
            + pow(this->imaginary, 2), 0.5);
            this->theta = atan(this->imaginary/this->real);
            this->polar = true;
        }
        void calculateCartesian() {
            assert(polar == true);
            this->real = this->magnitude * cos(this->theta);
            this->imaginary = this->magnitude * sin(this->theta);
        }

        // Operator overloading
        Complex operator + (Complex c) {
            Complex comp = Complex(this->getReal() + c.getReal(), this->getImaginary() + c.getImaginary());
            comp.calculatePolar();
            return comp;
        }
        Complex operator - (Complex c) {
            Complex comp = Complex(this->getReal() - c.getReal(), this->getImaginary() - c.getImaginary());
            comp.calculatePolar();
            return comp;
        }
        Complex operator * (Complex c) {
            if (this->polar == false) this->calculatePolar();
            if (c.polar == false) c.calculatePolar();
            return Complex(this->magnitude * c.magnitude, this->theta + c.theta, POLAR);
        }
        Complex operator / (Complex c) {
            if (this->polar == false) this->calculatePolar();
            if (c.polar == false) c.calculatePolar();
            return Complex(this->magnitude / c.magnitude, this->theta - c.theta, POLAR);
        }
};