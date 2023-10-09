#include <iostream>
using namespace std;

struct ListStruct {
    int arr[8];
};

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

ListStruct pureShuffle(int pList[], int size) {
    ListStruct pList_struct;
    for (int i = 0; i < size; i++) {
        pList_struct.arr[i] = pList[i];
    }
    int x = -1;
    int y = -1;
    int temp = -1;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        x = pList_struct.arr[i];
        y = pList[rand() % size];
        temp = x;
        x = y;
        y = temp;
    }
    return pList_struct;
}

int main() {
    cout << endl;
    int numbers[8] = {23, 47, 56, 89, 92, 100, 98, 37};
    cout << "ORIGINAL LIST: " << endl;
    for (int i = 0; i < 8; i++) {
        cout << numbers[i] << ", ";
    }

    cout << "\n\n";
    cout << "AFTER MODIFIER FUNCTION SHUFFLE: " << endl;
    modifierShuffle(numbers, 8);
    for (int i = 0; i < 8; i++) {
        cout << numbers[i] << ", ";
    }

    cout << "\n\n";
    int numbers2[8] = {94, 45, 96, 85, 12, 34, 70, 63};
    cout << "ORIGINAL LIST: " << endl;
    for (int i = 0; i < 8; i++) {
        cout << numbers2[i] << ", ";
    }

    cout << "\n\n";
    cout << "AFTER PURE FUNCTION SHUFFLE: " << endl;
    ListStruct demo = pureShuffle(numbers2, 8);
    for (int i = 0; i < 8; i++) {
        cout << demo.arr[i] << ", ";
    }

    cout << endl;
    return 0;
}