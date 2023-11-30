#include <math.h>

class Complex {
    double real, imaginary;
    double magnitude, theta;
    bool polar;

    public:
        Complex() {
            this->real = 0; 
            this->imaginary = 0;
            this->polar = false;
        }
        Complex(double r, double i) {
            this->real = r; this->imaginary = i;
            this->polar = false;
        }

        // Accessor functions
        double getReal() {
            return this->real;
        }
        double getImaginary() {
            return this->imaginary;
        }


        // Modifier functions
        void calculatePolar() {
            this->magnitude = pow(pow(this->real, 2) 
            + pow(this->imaginary, 2), 0.5);

            this->theta = atan(this->imaginary/this->real);
        }
};