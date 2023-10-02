#include <iostream>
using namespace std;

int main() {
    int x = 0;

    /* The & operator returns the memory address of the
    variable. The * after int is required when creating 
    a pointer. */
    int* pointer = &x;

    /* This line prints the memory address of the variable
    x.*/
    cout << long(&x) << endl;

    /* The asterisk is a derefrencing operator. It takes 
    a pointer and returns the value stored at the memory
    address stored in the pointer.*/
    cout << *pointer;

    return 0;
}