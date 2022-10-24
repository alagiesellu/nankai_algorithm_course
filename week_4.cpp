/** Exercise 4
 *
    ■ Different Ways to Add Parentheses

    ■ Description
        – Given a string expression of numbers and operators, return all possible results from computing all the
          different possible ways to group numbers and operators. You need to return the answers in increasing order.
        – You don't need to merge the same items in the answer.
        – The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.

    ■ Input
        – A string expression of numbers and operators.

    ■ Output
        – All possible results from computing all the different possible ways to group numbers and operators.

    ■ Deadline
        – 2022-10-4 23:59:00 GMT+8
 * */

#include <bits/stdc++.h>

using namespace std;

vector<int> compute_expression(string& input, int start, int end){

    vector<int> answers;

    for(int i = start; i <= end; i++) {

        char character = input[i];

        if(character == '*' || character == '+' || character == '-') {

            vector<int> left_answers = compute_expression(input, start, (i - 1));
            vector<int> right_answers = compute_expression(input, (i + 1), end);

            for(int left_ans : left_answers) {
                for(int right_ans : right_answers) {

                    int ans;

                    if(character == '*')
                        ans = left_ans * right_ans;

                    else if(character == '+')
                        ans = left_ans + right_ans;

                    else
                        ans = left_ans - right_ans;

                    answers.push_back(ans);
                }
            }
        }
    }

    if(answers.empty()) {
        answers.push_back(
                stoi(input.substr(start, end - start + 1))
        );
    }

    return answers;
}

int main() {

    string input;

    cin >> input;

    int input_size = (int) input.size();

    vector<int> answers = compute_expression(input, 0, input_size - 1);

    sort(answers.begin(), answers.end());

    cout << "[";

    int last_answer = answers.back();
    answers.pop_back();

    for(int answer : answers) {
        cout << answer << ",";
    }

    cout << last_answer << "]";

    return 0;
}