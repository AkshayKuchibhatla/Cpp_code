#include <iostream>
#include <cmath>
using namespace std;

void powersOf2(int number) {
    number++;
    for(int i = 0; i < number; i++) {
        cout << pow(2,i) << endl;
    }
}

int main() {
    powersOf2(16);
    return 0;
}