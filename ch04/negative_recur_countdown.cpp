#include <iostream>
using namespace std;

// A recursive function that counts down from a specified number.
void countdown(int n) {
    if (n == 0) { // the countdown stops when it reaches 0.
        cout << n << endl;
        cout << "Blastoff!" << endl;
    } else {
        cout << n << endl;
        countdown(n-1);
    }
}

int main() {
    /* The problem arises when a negative number is
    passed into the function. The function keeps 
    counting down but it just goes deep into negative 
    numbers instead of ever reaching 1 and breaking 
    out of recursion. The output for this program is 
    stored in infinite_recursion.txt*/
    countdown(-10);
    return 0;
}