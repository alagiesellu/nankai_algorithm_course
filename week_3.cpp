/** Created on 9/23/22.
 *
 *  Exercise 3
 *
    ■ 3-sum problem

    ■ Description
        – Suppose an array consisting of n integers that does not duplicate.
        – Count the number of triples (a, b, c) in the array such that a+b+c=0.
        – n ∈ [3, 5000).

    ■ Input
        – The first line is an integer n indicating how many integers.
        – The second line is an array containing n integers.

    ■ Output
        – The number of triples (a, b, c) in the array such that a+b+c=0..

    ■ Deadline
        – 2022-9-27 23:59:00 GMT+8
 * */

#include <iostream>
#include <string>

using namespace std;

int getArraySize() {

    int size;
    string sizeInput;

    getline(cin, sizeInput);
    size = stoi(sizeInput);

    return size;
}

void splitInputIntoArray(int* numbers, int& arraySize, const string& input)
{
    int spacePos, currPos = 0, prevPos = 0, i = 0;
    string number;

    do {
        spacePos = input.find(' ', currPos);
        if(spacePos >= 0) {
            currPos = spacePos;
            number = input.substr(prevPos, currPos - prevPos);
            numbers[i++] = stoi(number);
            prevPos = currPos++;
        }


    } while( spacePos >= 0);

    number = input.substr(prevPos,input.length());
    numbers[i] = stoi(number);
}

void getInputs(int* numbers, int& arraySize) {

    string numbersInput;
    getline(cin, numbersInput);

    splitInputIntoArray(numbers, arraySize, numbersInput);
}

void calculateTriples(const int* numbers, int& arraySize) {

    int count = 0, a, b, c;

    for (a = 0; a < arraySize; a++) {
        for (b = a + 1; b < arraySize; b++) {
            for (c = b + 1; c < arraySize; c++) {
                if (numbers[a] + numbers[b] + numbers[c] == 0) {
                    count++;
                }
            }
        }
    }

    cout << count;

}

int main() {

    int arraySize = getArraySize();

    int numbers[arraySize];

    getInputs(numbers, arraySize);

    calculateTriples(numbers, arraySize);

    return 0;
}