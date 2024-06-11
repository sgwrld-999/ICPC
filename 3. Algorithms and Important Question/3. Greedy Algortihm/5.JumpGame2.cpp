#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Jump Game 2
Problem link: https://leetcode.com/problems/jump-game-ii/
Explanation:
We've given an array of non-negative integers. We have to find the minimum number of jumps to reach the last index.
We can jump from the ith index to the i + nums[i] index.

Approach1 : Brute force : Recursion
Approach2 : DP + Recursion
Approach3 : Greedy

Greddy intiution:
We've to find the minimum number of jumps to reach the last index.
We can jump from the ith index to the i + nums[i] index.
WE will instead of storing the individual jumps we will store the farthest index we can reach from the current index.
How? By range of l and r.
L : Lower bound of the range.
R : Upper bound of the range.
Farthest : The farthest index we can reach from the current index.

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int r = 0;
        int l = 0;
        int n = nums.size();

        while (r < n - 1) {
            farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
