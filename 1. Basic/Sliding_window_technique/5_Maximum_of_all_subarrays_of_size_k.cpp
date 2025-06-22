#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Problem Link: https://leetcode.com/problems/sliding-window-maximum/
Explanation: 
    TUF: https://takeuforward.org/data-structure/sliding-window-maximum/
    MySolution: https://leetcode.com/problems/sliding-window-maximum/solutions/6871222/sliding-window-deque-by-sgwrld_999-u09q
*/

class Solution {
public:
    int getMax(vector<int>& nums, int left, int right, int k) {
        int maxi = INT_MIN; 

        for(int i = left; i <= right; i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    // Remove the first implementation to avoid duplicate definition errors

    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        deque<int> dq;

        vector<int> ans;

        int left = 0 ; 
        int right = 0 ;
        
        while(right < n){
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            if(dq.front() < left) dq.pop_front();

            if(right - left + 1 == k){
                ans.push_back(nums[dq.front()]);
                left++;
            }
            right++;
        }
        return ans;
    }
};



