#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Jump Game
Problem link: https://leetcode.com/problems/jump-game/
Explanation:
We've given an array of non-negative integers. We have to find whether we can reach the last index or not.
We can jump from the ith index to the i + nums[i] index.
If we can reach the last index then return true otherwise return false.

maxIdx: signifies the maximum index we can reach from the current index.
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIdx) return false; 

            maxIdx = max(maxIdx, i + nums[i]);
            if (maxIdx >= nums.size() - 1) return true; 
        }

        return maxIdx >= nums.size() - 1; 
    }
};