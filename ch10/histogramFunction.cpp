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

vector<int> histogram(vector<int> numbers, int upperLimit) {
    vector<int> histogram(upperLimit, 0);
    int index = 0;
    for (int i = 0; i < numbers.size(); i++) {
        index = numbers[i];
        histogram[index]++;
    }
    return histogram;
}

int main() {
    int userSize;
    int userUpperLimit;
    cout << "Enter a size for the vector... ";
    cin >> userSize;
    cout << endl;
    cout << "Enter an upper limit for the vector... ";
    cin >> userUpperLimit;
    cout << endl << endl;
    vector<int> userVector = randomVector(userSize, userUpperLimit);
    vector<int> userHistogram = histogram(userVector, userUpperLimit);
    cout << "HISTOGRAM:" << endl;
    for (int i = 0; i < userHistogram.size(); i++) {
        cout << i << ":\t" << userHistogram[i] << endl;
    }
    return 0;
}