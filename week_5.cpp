/** Exercise 5
 *
    ■ Maximum Subarray

    ■ Description
        – Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
        – A subarray is a contiguous part of an array.
        – If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

    ■ Input
        – The first line of the input is an integer n, which is the length of array.
        – Each of the next n lines contains a single integer in the array.

    ■ Output
        – The largest sum of the contiguous subarray.

    ■ Deadline
        – 2022-10-11 23:59:00 GMT+8

 * */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void getIntegerInput(int& input) {

    bool valid = false;

    do {
        cin >> input;

        if (cin.good()) {
            valid = true;
        } else {
            cin.clear();
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
}

int maximumSubarrayFirstAlgorithm(int numbers[], int length)
{
    int
        max_ending_here = 0,
        max_so_far = INT_MIN;

    for (int i = 0; i < length; i++) {
        max_ending_here += numbers[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int maximumCrossingSubarrayDivideAndConquer(int numbers[], int start, int mid, int end)
{
    int
        sum = 0,
        left_sum = INT_MIN,
        right_sum = INT_MIN;

    for (int i = mid; i >= start; i--) {
        sum = sum + numbers[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    for (int i = mid; i <= end; i++) {
        sum = sum + numbers[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum, right_sum, left_sum + right_sum - numbers[mid]);
}

int maximumSubarrayDivideAndConquer(int numbers[], int start, int end)
{
    if (start > end)
        return INT_MIN;

    if (start == end)
        return numbers[start];

    int mid = (start + end) / 2;

    int
        left = maximumSubarrayDivideAndConquer(numbers, start, mid - 1),
        right = maximumSubarrayDivideAndConquer(numbers, mid + 1, end),
        cross = maximumCrossingSubarrayDivideAndConquer(numbers, start, mid, end);

    return max(left, right, cross);
}

int main() {

    int arrayLength;

    getIntegerInput(arrayLength);

    int numbers[arrayLength];

    // Enter numbers.
    for (int i = 0; i < arrayLength; ++i) {
        getIntegerInput(numbers[i]);
    }

    int max = maximumSubarrayFirstAlgorithm(numbers, arrayLength);
//    cout << max << endl;

    max = maximumSubarrayDivideAndConquer(numbers, 0, arrayLength - 1);
    cout << max;

    return 0;
}