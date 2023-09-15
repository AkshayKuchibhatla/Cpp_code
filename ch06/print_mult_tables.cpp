#include <iostream>
using namespace std;

void print_multiples(int n, int upper)
{
    int i = 1;
    while (i <= upper) {
        cout << n * i << "   ";
        i = i + 1;
    }
    cout << endl;
}

void print_mult_table(int upper)
{
    int i = 1;
    while (i <= upper) {
        print_multiples(i, upper);
        i = i + 1;
    }
}

int main() {
    print_mult_table(12);
    return 0;
}