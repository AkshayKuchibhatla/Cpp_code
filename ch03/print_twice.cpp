#include <iostream>
using namespace std;

void print_twice(char phil) {
    cout << phil << phil << endl;
}

int main() {
    /* passing a char will work, because the parameter
    of the function is defined as type character.*/
    print_twice('B');

    /*passing an integer will return a warning, and
    only an empty line will be printed in terminal.*/
    print_twice(3);

    /*passing multiple characters won't return a
    compiling error, but it will only print the
    last character in the phrase, which in this 
    case is '!'.*/
    print_twice('hello world!');

    /*passing a string instead of a character 
    returns a compiling error. Even VSCode
    intellisense says it's wrong.*/
    print_twice("This won't work.");

    return 0;
}