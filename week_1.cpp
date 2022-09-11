#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {

    int arraySize;
    cin >> arraySize;

    while (arraySize <= 1 || arraySize >= 1000) {
        cin >> arraySize;
    }

    int array[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cin >> array[i];
    }

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

    for (int i = 0; i < arraySize - 1; i++) {
        cout << array[i] << " ";
    }

    cout << array[arraySize - 1] << "\n";

    return 0;
}
