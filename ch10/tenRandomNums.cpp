#include <iostream>
using namespace std;

void print_random_numbers(int number) {
    srand(time(NULL));
    for (int i = 0; i < number; i++) {
        cout << rand() % 1000 << endl;
    }
}

int main() {
    print_random_numbers(10);
    return 0;
}