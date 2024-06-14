#include <bits/stdc++.h>
using namespace std;

/*
Problem name : Valid Parenthesis String
Problem link : https://leetcode.com/problems/valid-parenthesis-string/`
Problem Statement : Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
Explanation:
Approach 1: Brute force -> Generate all possible strings and check if they are valid or not by recursively checking each character. For better time and space complexity, we can use dynamic programming.
Approach 2: Trying all the possible ways with 2 variables 
    Initialize two variables mini and maxi with 0.
    Iterate over the string s.
    For each character in s:
        If the character is '(':
            Increment both mini and maxi.
        If the character is ')':
            Decrement both mini and maxi.
        If the character is '*':
            Decrement mini and increment maxi.
        If mini is less than 0:
            Set mini to 0.
        If maxi is less than 0:
            Return false.
    Return mini == 0.

    Let's understand with an example: 
    s = "(*))"
    mini = 0, maxi = 0
    i = 0
    s[0] = '('
    mini = 1, maxi = 1
    i = 1
    s[1] = '*'
    mini = 0, maxi = 2
    i = 2
    s[2] = ')'
    mini = -1, maxi = 1
    mini is less than 0, so set mini to 0
    i = 3
    s[3] = ')'
    mini = -1, maxi = 0
    mini is less than 0, so set mini to 0

    mini == 0, so return true.


    Here 0 signifies that all the open brackets can be matched.
    Time complexity: O(n)
    Space complexity: O(1)
    


*/
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                mini++;
                maxi++;
            } else if(s[i] == ')') {
                mini--;
                maxi--;
            } else {  // when s[i] is '*'
                mini--;  // '*' can be considered as ')'
                maxi++;  // '*' can be considered as '('
            }
            if(mini < 0) {
                mini = 0;  // ensure mini does not go below 0
            }
            if(maxi < 0) {
                return false;  // if maxi is negative, the string is invalid
            }
        }

        return mini == 0;  // ensure all open brackets can be matched
    }
};

int main() {
    Solution s;
    string str = "(*))";
    cout << s.checkValidString(str) << endl;
    return 0;
}