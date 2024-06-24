#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Subsets 2
Problem link : https://leetcode.com/problems/subsets-ii/
Explanation : Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Approach 1 : Pick and not pick approach. We can either pick the element or not pick the element.
Appraoch 2 : Recursion transition. We can avoid the duplicate subsets by not picking the same element again. We can do this by checking if the current element is same as the previous element and if it is then we'll skip it.

*/
class Solution {
public:
    void solve(int idx,vector<int>&nums ,vector<int>& storeDS,vector<vector<int>>& ans , int N){
        ans.push_back(storeDS);
        for(int i = idx ; i < N ; i++){
            if(i != idx && nums[i] == nums[i-1]) continue ;// i != idx is used to avoid the duplicate subsets by not picking the same element again. And picking up the one element again 
            storeDS.push_back(nums[i]);
            solve(i+1,nums,storeDS,ans,N);
            storeDS.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int N = nums.size();
        vector<int> storeDS;
        sort(nums.begin(),nums.end());
        solve(0,nums,storeDS,ans,N);
        return ans;
    }
};