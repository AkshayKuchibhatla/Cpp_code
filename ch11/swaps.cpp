#include <iostream>
using namespace std;

void wont_swap(char a, char b) {
    /* This first swap function doesn't work, because it swaps
    the values of the variables passed rather than the memory
    addresses. Inside the scope of the function, the values 
    are switched but in reality, the variables remain unchanged.*/
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: " << long(&a) << endl;
    cout << "address of b: " << long(&b) << endl;
    char temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

void will_swap(char& a, char& b) {
    /* This function works, because it actually switches the 
    memory addresses of the 2 variables passed, so the variables
    are fundamentally changed.*/
    cout << "a: " << a << "  b: " << b << endl;
    cout << "address of a: " << long(&a) << endl;
    cout << "address of b: " << long(&b) << endl;
    char temp = a;
    a = b;
    b = temp;
    cout << "a: " << a << "  b: " << b << endl;
}

void will_swap_with_pointers(char* a, char* b)
{
    cout << "a: " << *a << "  b: " << *b << endl;
    cout << "address of a: " << long(a) << endl;
    cout << "address of b: " << long(b) << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "a: " << *a << "  b: " << *b << endl;
}

int main() {
    char x = 'x';
    char y = 'y';

    cout << "x: " << x << "  y: " << y << endl;
    cout << "address of x: " << long(&x) << endl;
    cout << "address of y: " << long(&y) << endl;
    cout << "Calling wont_swap..." << endl;
    wont_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;
    cout << "Calling will_swap..." << endl;
    will_swap(x, y);
    cout << "x: " << x << "  y: " << y << endl;
    char c = 'c';
    char d = 'd';
    cout << "Calling will_swap_with_pointers..." << endl;
    will_swap_with_pointers(&c, &d);
    return 0;
}