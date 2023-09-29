#include <iostream>
using namespace std;

void incrementVariable(const double& x) {
    //x++; // This returns an error, because it means that
    // you're trying to modify a constant, which is an 
    // immutable data type. The code won't even compile.
}

int main() {
    double x;
    cout << "Enter a number: ";
    cin >> x;
    const double userInput = x;
    incrementVariable(userInput);
    cout << userInput;
    return 0;
}