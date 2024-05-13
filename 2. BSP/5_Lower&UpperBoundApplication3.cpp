#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Find the first and last occurrences of a number in a sorted array   
Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Explanation  : Sorted array -> Means Binary Search is applicable 
               We need to find the occurence of a number in the array first and last.So, for 
               first lower bound and for last upper bound is used. Why? Because lower bound will find the smallest index where
               the number is present and upper bound will find the largest index where the number is present.
*/
/*
    Solution 1 : Using STL lower_bound and upper_bound
    Time Complexity : O(2logn)
    Space Complexity : O(1)
    Solution 2 : Using Binary Search : In this first we eleminate the left half when we find the number and then we eleminate the right half for the last occurence.
    Time Complexity : O(2logn)
    Space Complexity : O(1)
*/

class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1); // Initialize the result vector with -1
        
        // Find the first occurrence
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            res[0] = it - nums.begin();
        }
        
        // Find the last occurrence
        it = upper_bound(nums.begin(), nums.end(), target);
        if (it != nums.begin()) {
            res[1] = it - nums.begin() - 1;
        }
        
        return res;
    }
};


class Solution2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1); // Initialize the result vector with -1
        
        long long low = 0;
        long long high = nums.size() - 1;
        long long start = -1, end = -1;
        
        // Finding the leftmost index
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                start = mid;
                high = mid - 1; // Search in the left half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        low = 0;
        high = nums.size() - 1;
        
        // Finding the rightmost index
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                end = mid;
                low = mid + 1; // Search in the right half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        res[0] = start;
        res[1] = end;
        return res;
    }
};