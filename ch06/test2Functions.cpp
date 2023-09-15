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
    srand(time(NULL));
    if (input == 'l') {
        loop_forever(rand ()% 101);
    } else {
        recurse_forever(rand() % 101);
    }

    return 0;
}