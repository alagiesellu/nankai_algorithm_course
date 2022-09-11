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

int main() {

    cout << "Enter Size : ";
    int arraySize;
    cin >> arraySize;

    while (arraySize <= 1 || arraySize >= 1000) {
        cin >> arraySize;
    }

    int array[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

    sortArray(array, arraySize);

    cout << endl << "Sorted Array : " << endl;
    for (int i = 0; i < arraySize - 1; i++) {
        cout << array[i] << " ";
    }

    cout << array[arraySize - 1] << "\n";

    return 0;
}
