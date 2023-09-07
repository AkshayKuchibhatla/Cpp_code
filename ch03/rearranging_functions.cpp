#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << "First Line." << endl;
    new_line();
    cout << "Second Line." << endl;
    return 0;
}

// The definition of the new_line() 
// function is placed AFTER the definition 
// of the main() function. This means that 
// the main() function won't run because
// new_line() hasn't been defined yet. 
// the program will return a compiling
// error.
void new_line()
{
    cout << endl;
}
