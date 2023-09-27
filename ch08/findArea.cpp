#include <iostream>
using namespace std;

struct Rectangle {
    float height, width;
};

float findArea(Rectangle rex) {
    return rex.height * rex.width;
}

int main() {
    Rectangle rect;

    cout << endl;
    cout << "Height: ";
    cin >> rect.height;
    cout << "Width: ";
    cin >> rect.width;
    cout << endl;

    cout << "The area of your rectangle is " 
    << findArea(rect) << ".";
    return 0;
}