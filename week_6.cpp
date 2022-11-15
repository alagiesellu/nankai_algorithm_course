/** Exercise 6
 *
    ■ Longest Nice Substring

    ■ Description
    A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and
    lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not
    because 'b' appears, but 'B' does not.

    ■ Input
    A string s

    ■ Output
    Return the longest substring of 𝑠 that is nice. If there are multiple, return the substring of the earliest
    occurrence. If there are none, return "none".

 * */
#include <iostream>
#include <string>

using namespace std;

char getPair(char character) {
    return isupper(character) ? tolower(character) : toupper(character);
}

bool isNice(string& sub_string) {
    char pair;
    for (int i = 0; i < sub_string.length(); i++) {
        pair = getPair(sub_string[i]);

        if (sub_string.find(pair) == string::npos)
            return false;
    }
    return true;
}

string findNiceString(string& input) {

    int max_index = input.length() - 1;
    string
        sub_string,
        longest_nice;

    for (int i = 0; i <= max_index; i++) {
        for (int j = max_index; i < j; j--) {

            sub_string = input.substr(i, j - i + 1);

            if (isNice(sub_string) && sub_string.length() > longest_nice.length())
                longest_nice = sub_string;
        }
    }

    return longest_nice.empty() ? "none" : longest_nice;
}

int main() {

    string input;

    getline(cin, input);

    string niceString = findNiceString(input);

    cout << niceString;

    return 0;
}