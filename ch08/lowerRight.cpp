#include <iostream>
using namespace std;

struct Point {
    float x, y;
};

struct Rectangle {
    Point topLeftCorner;
    float height, width;
};

Point lowerRight(Rectangle r) {
    Point lowRight;
    lowRight.x = r.topLeftCorner.x + r.width;
    lowRight.y = r.topLeftCorner.y - r.height;
    return lowRight;
}

int main() {
    Rectangle rect;

    cout << endl;
    cout << "Height: ";
    cin >> rect.height;
    cout << "Width: ";
    cin >> rect.width;
    cout << endl;
    cout << "Top left corner x: ";
    cin >> rect.topLeftCorner.x;
    cout << "Top left corner y: ";
    cin >> rect.topLeftCorner.y;
    cout << endl;

    Point output = lowerRight(rect);
    cout << "The lower right corner of the rectangle is at (" 
    << output.x << ", " << output.y << ").";
    return 0;
}