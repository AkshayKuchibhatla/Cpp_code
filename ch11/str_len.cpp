#include <iostream>
using namespace std;

int str_len(char x[]) {
    return sizeof(x) / sizeof(char);
}

int main() {
    char thing[] = "Hello world!!!!!!!!!!!!!!";
    cout << str_len(thing);
    return 0;
}