/** Created on 9/14/22.
 *
 *  Exercise 2
 *
    ■ Find Majority Numbers

    ■ Description
        – Suppose an array consists of n integers.
        – Find all the elements that appear more than ⌊n/3⌋times.

     ■ Input
        – The first line of the input is an integer n, which is the number of integer. Each of the next n lines contains a single non-negative integer.

    ■ Output
        – Each line of the output contains an integer that appears more than ⌊n/3⌋times, and the output integers are in ascending order.

    ■ Deadline
        – 2022-9-20 23:59:00 GMT+8
 * */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getIntegerInput() {

    int input = 0;

    while (input < 1)
        cin >> input;

    return input;
}

void calculateRepetitions(const int* array, int& arraySize) {

    int repetitionCount = arraySize / 3;

    int i = 0, current, count;

    while (i < arraySize) {
        current = array[i];
        count = 1;

        while (current == array[i + count]) {
            count++;
        }
        i += count;

        // if pass repetition count, print
        if (count > repetitionCount)
            cout << current << " ";
    }

    cout << endl;
}

void generateArray(int* array, int& arraySize) {

    for (int i = 0; i < arraySize; ++i) {
        array[i] = getIntegerInput();
    }
    cout << endl;
}

int main() {

    int arraySize = getIntegerInput();

    int array[arraySize];

    generateArray(array, arraySize);

    sort(array, array + arraySize);

    calculateRepetitions(array, arraySize);

    return 0;
}