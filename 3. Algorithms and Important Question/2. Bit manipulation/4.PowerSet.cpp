#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
/*
Problem name: Subsets
Problem link: https://leetcode.com/problems/subsets/

Given an integer array nums of unique elements, return all possible subsets (the power set).
Approach:
1. Recursion
2. Bit Manipulation

Approach 2:
If we consider every element in the array, there are two choices, either we can include the element in the subset or we can exclude the element from the subset.
So, we can represent the choice of including or excluding the element in the subset using the bits.
Including -> 1
Excluding -> 0

Lets take an example:
nums = [1, 2, 3]
Total number of subsets = 2^3 = 8
So, the subsets are:
1. 000 -> []
2. 001 -> [3]
3. 010 -> [2]
4. 011 -> [2, 3]
5. 100 -> [1]
6. 101 -> [1, 3]
7. 110 -> [1, 2]
8. 111 -> [1, 2, 3]

So, we can see that the subsets are nothing but the binary representation of the numbers from 0 to 7.
So, we can iterate from 0 to 7 and check the bits of the number and include the element in the subset if the bit is set.


*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int totalSubSets = pow(2, n);

        for (int i = 0; i < totalSubSets; i++) {
            vector<int> list;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }

        return ans;
    }
};