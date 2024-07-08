#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Manacher's Algorithm
Problem Link : https://cp-algorithms.com/string/manacher.html
Problem Description :
Manacher's Algorithm is used to find the longest palindromic substring in a string.
The algorithm is based on the concept of palindrome and the idea of dynamic programming.
The algorithm
1. Preprocess the string to insert special characters between each character and at the beginning and end of the string.
2. Initialize an array to store the length of the palindrome centered at each character.
3. Initialize two pointers, left and right, to keep track of the palindrome centered at the current character.
4. Iterate through the string and update the palindrome length array.
5. Return the maximum palindrome length and the corresponding substring.
The time complexity of the algorithm is O(n), where n is the length of the input string.
*/
class Solution{
    public:
    vector<int> manacher_odd(string s){
        int n = s.size();
        s = '#' + s + '$';
        vector<int> p(n+2);
        int left = 1 , right = 1;
        for(int i = 1 ; i <= n ; i++){
            p[i] = max(0,min(right-i,p[left+(right-i)]));
            while (s[i-p[i]] == s[i+p[i]])
            {
                p[i]++;
            }
            if(i+p[i] > right){
                left = i;
                right = i+p[i];
            }
        }
        return vector<int>(begin(p)+1,end(p)-1);
    }
};

int main(){
    Solution s;
    string str = "abacaba";
    vector<int> res = s.manacher_odd(str);
    for(auto i : res){
        cout<<i<<" ";
    }
}