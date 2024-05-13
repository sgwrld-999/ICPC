#include <bits/stdc++.h>
using namespace std;
/*
problem : Search Insert Position
Problem Link : https://leetcode.com/problems/search-insert-position/
Explanation : The problem is to find the index of the target element in the sorted array. 
If the target element is not present in the array then return the index where the target element should be inserted to keep the array sorted.
Hint for the Binary search or Lower Bound is that the array is sorted and we need to find the index of the target element.
Why lower bound because we need to find the index where the target element should be inserted to keep the array sorted or 
the index of the first element which is greater than or equal to the target element and that's the definition of the lower bound.

*/
class Solution {
public:
    int lowerBound(vector<int>& nums,int low,int high,int target){
        if(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) return lowerBound(nums,low,mid-1,target);
            else return lowerBound(nums,mid+1,high,target);
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lowerBound(nums,0,nums.size()-1,target);
    }
};


