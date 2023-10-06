#include <iostream>
using namespace std;

void swapListElements(int* list, int index1, int index2) {
    int* listPointer = list;
    int* firstElement = listPointer + index1;
    int* secondElement = listPointer + index2;
    int temp;
    temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void modifierShuffle(int pList[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        swapListElements(pList, i, rand() % size);
    }
}

int* pureShuffle(int pList[], int size) {
    int copy[] = *pList;
    int x;
    int y;
    int temp;
    srand(NULL);
    for (int i = 0; i < size; i++) {
        x = pList[i];
        y = pList[rand() % size];
        temp = x;
        x = y;
        y = temp;
    }
    return pList;
}

int main() {
    int numbers[8] = {23, 47, 56, 89, 92, 100, 98, 37};
    cout << "ORIGINAL LIST: " << endl;
    int n = sizeof(numbers) / sizeof(int);
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }

    cout << endl;
    cout << "AFTER MODIFIER FUNCTION SHUFFLE: " << endl;
    modifierShuffle(numbers, n);
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }

    cout << endl;
    int numbers2[8] = {94, 45, 96, 85, 12, 34, 70, 63};
    cout << "ORIGINAL LIST: " << endl;
    n = sizeof(numbers2) / sizeof(int);
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }

    cout << endl;
    cout << "AFTER PURE FUNCTION SHUFFLE: " << endl;
    // int x[] = pureShuffle(numbers2, n);
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }
    return 0;
}