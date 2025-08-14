/*
Problem name: Selection Sort
Problem link LeeCode : https://leetcode.com/problems/sort-an-array/

Code working and flow: 
1. We will find the minimum element in the array and swap it with the first element.   
2. We will repeat the above step for the remaining elements of the array.

Time complexity : O(n^2)
Space complexity : O(1)

Dry run example: 
arr = [9,1,5,6,2,3]
After 1st iteration : [1,9,5,6,2,3] // 1 is the minimum element
After 2nd iteration : [1,2,5,6,9,3] // 2 is the minimum element
After 3rd iteration : [1,2,3,6,9,5] // 3 is the minimum element
After 4th iteration : [1,2,3,5,9,6] // 5 is the minimum element
After 5th iteration : [1,2,3,5,6,9] // 6 is the minimum element
After 6th iteration : [1,2,3,5,6,9] // 9 is the minimum element

Hence the element is sorted.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> SelectionSortsortArray(vector<int>& nums) {
        int miniIdx = 0; 
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            miniIdx = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[miniIdx]) {
                    miniIdx = j;
                }
            }
            swap(nums[i], nums[miniIdx]);
        }
        return nums;
    }

     

    
};