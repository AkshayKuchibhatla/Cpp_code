#include <iostream>
using namespace std;
void myFunction(int *myNumbers) { 
//     cout << "size:" << sizeof(*myNumbers) << endl;
//   for (int i = 0; i < 5; i++) {
//     cout << myNumbers[i] << "\n";
//   }
cout << myNumbers[0] << endl;
cout << myNumbers[6] << endl;
}


int main() {
  int myNumbers[6] = {10, 20, 30, 40, 50, 0};
  myFunction(myNumbers);
  return 0;
}