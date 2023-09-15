#include <iostream>
using namespace std;

void loop_forever(int n) {
    // True is always true, so the while loop never stops.
    while (true) {
        cout << "n is now " << n << "." << endl;
        n = n + 1;
    }
}

void recurse_forever(int n) {
    /*You always have to be carefull when using recursion
    so as to not be stuck in an infinite loop like this:*/
    cout << "n is now " << n << "." << endl;
    recurse_forever(n + 1);
}

int main() {
    /*Since both functions run forever, only one would
    run at a time, so the program asks for user input to 
    decide which one to run.*/
    char input;
    while (input != 'l' && input != 'r') {
        cout << "Do you want to loop forever (l) or recurse forever (r)? ";
        cin >> input;
        cout << endl;
    }

    /*Whenever a program runs, it takes up an allotted
    section of stack memory, which is a part of RAM on
    a computer that stores information on programs while
    they're running.*/

    if (input == 'l') {
        loop_forever(1);
    } else {
        recurse_forever(1);
    }

    return 0;
}