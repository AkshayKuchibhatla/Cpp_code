#include <iostream>
using namespace std;

void compare(int a, int b) {
    /* Compares 2 integers and prints which 
    one is greater than the other.*/
    if (a > b) {
        cout << a << " is greater than " << b;
    } else {
        cout << b << " is greater than " << a;
    }
}

int main() {
    cout << endl;
    int v;
    int u;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        v = rand() % 101;
        u = rand() % 101;
        compare(u, v);
        cout << endl;
        cout << endl;
    }
    return 0;
}