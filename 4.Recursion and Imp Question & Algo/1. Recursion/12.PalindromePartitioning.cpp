#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Palindrome Partitioning
Problem Link : https://leetcode.com/problems/palindrome-partitioning/

Solution:

*/
class Solution {
public:
    void solve(vector<vector<string>>& ans,vector<string>& path,string s,int idx){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = idx ; i < s.size() ; i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(ans,path,s,i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;

            start++;
            end--;
        }

        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> path ;
        solve(ans,path,s,0);
        return ans;
    }
};