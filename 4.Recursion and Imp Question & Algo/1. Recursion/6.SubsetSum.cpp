#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Subset
Problem link : https://leetcode.com/problems/subsets/
Explanation : Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Approah1 : Pick and not pick approach. We can either pick the element or not pick the element.

*/
class Solution {
public:
    void findSum(int index, vector<vector<int>>& ans, vector<int> currentSubset, vector<int> arr, int n, int sum) {
        if (index >= n) {
            ans.push_back(currentSubset);
            return;
        }
        currentSubset.push_back(arr[index]);  // Include current element in the subset
        findSum(index + 1, ans, currentSubset, arr, n, sum + arr[index]);  // Call with included element
        currentSubset.pop_back();  // Exclude the current element for the next call
        findSum(index + 1, ans, currentSubset, arr, n, sum);  // Call without included element
    }

    vector<vector<int>> subSetSum(vector<int> arr, int n) {
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        findSum(0, subsets, currentSubset, arr, n, 0);
        return subsets;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = s.subSetSum(arr, arr.size());
    sort(ans.begin(), ans.end());
    for (auto subset : ans) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "} ";
    }
    return 0;
}
