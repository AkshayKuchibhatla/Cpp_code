#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> randomVector(int size, int upperLimit) {
    vector<int> thing (size, 0);
    srand(time(NULL));
    for (int i = 0; i < thing.size(); i++) {
        thing[i] = rand() % upperLimit;
    }
    return thing;
}

int howMany(vector<int> numbers, int value) {
    int count = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == value) count++;
    }
    return count;
}

void histogram(vector<int> numbers, int upperLimit) {
    cout << "value\t\thow many" << endl;
    for (int value = 0; value < upperLimit; value++) {
        cout << value << "\t\t" << howMany(numbers, value) << endl;
    }
}

int main() {
    vector<int> x = randomVector(100000, 10);
    cout << endl;
    histogram(x, 10);
    return 0;
}