/** Created on 9/01/2022
 *
 *  Exercise 1
 *
    ■ Sort Array

    ■ Description
        – Suppose an array consists of N integers.
        – Write a program to sort the elements of the array and output the sorted array.
        – The length of the array is smaller than 1000.

    ■ Input
        – The first line of input is an integer n, representing the total number of n elements in the array.
        – The next n lines are the elements in the array.

    ■ Output
        – Output a sorted array, with each element separated by a space and the last element followed by a newline character (\n) instead of a space.

    ■ Deadline
        – 2022-9-13 23:59:00 GMT+8
 * */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int arraySize = 0;

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
