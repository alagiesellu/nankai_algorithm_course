#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Bobble sort algorithm.
 * */
void sortArray(int *array, int arraySize) {
    int temp;
    for (int i = 0; i < arraySize; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int readNumber() {
    int input;

    while(true) {
        cin >> input;

        if(cin.fail()) {
            cout << " * Wrong input, enter again: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else {
            break;
        }
    }

    return input;
}

int main() {

    cout << "Enter Array Size : ";
    int arraySize = readNumber();

    while (arraySize <= 1 || arraySize >= 1000) {
        cout << " * Array size should be less than 1000, enter again: ";
        arraySize = readNumber();
    }

    int array[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cout << "Enter Element [" << i << "] : ";
        array[i] = readNumber();
    }

    sortArray(array, arraySize);

    cout << endl << "Sorted Array : ";
    for (int i = 0; i < arraySize - 1; i++) {
        cout << array[i] << " ";
    }

    cout << array[arraySize - 1] << "\n";

    return 0;
}
