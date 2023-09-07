#include<iostream>
#include<cstdlib>
using namespace std;

void print_random_number() {
	srand((unsigned) time(NULL));
	int random = rand();
	cout<<random<<endl;
}

int main() {
    /*this is a function without a return value
    included as part of an arithmetic expression.
    This code will return a compiling error.*/
    print_random_number() * 30;
	return 1;
}