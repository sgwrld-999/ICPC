#include <iostream>
#include <string>
using namespace std;

/*
According to the question, we've to find the longest string in the given string among the given partitions. 

Key takesways;
1. No matter the partitions the longest string will be one and it'll have the maximum allowed length. 
2. "max" function of C++ evalute the string character by character by there ASCII value of lexographical order.
*/
class Helper {
public: 
    string longestString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int n = word.length();
        string res = "";

        for (int i = 0; i < n; i++) {
            int len = min(n - numFriends + 1, n - i);
            string candidate = word.substr(i, len);
            res = max(res, candidate);
        }

        return res;
    }
};

int main() {
    string word;
    cout << "Enter the word: ";
    cin >> word;

    int numFriends;
    cout << "Enter number of friends: ";
    cin >> numFriends;

    Helper helper;
    string ans = helper.longestString(word, numFriends);
    cout << "Lexicographically largest string: " << ans << endl;

    return 0;
}
