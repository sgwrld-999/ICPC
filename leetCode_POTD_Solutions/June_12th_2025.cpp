#include<iostream>
#include<vector>
/*
 What to Say in the Interview
"First, I handled the edge case with only two elements."

"Then, I iterated through the array to compute the difference between adjacent elements and kept track of the maximum difference."

"Finally, I optionally considered the circular difference between the last and first element, if required."

"I used abs() to ensure the distance is always non-negative, since we're concerned with magnitude."


*/ 
class Solution {
public:
    // Thought Process:
    // 1. The problem is to find the maximum absolute difference between adjacent elements.
    // 2. If only two elements, return their absolute difference directly.
    // 3. Otherwise, iterate through the array to find max difference between adjacent pairs.
    // 4. Additionally, check difference between last and first if treating array circularly.
    
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // Edge case: not enough elements for comparison
        if (n == 2) return abs(nums[0] - nums[1]); // Only one adjacent pair

        int maxDiff = INT_MIN;

        for (int i = 1; i < n; i++) {
            int diff = abs(nums[i] - nums[i - 1]);
            maxDiff = max(maxDiff, diff);
        }

        // Optional: if circular comparison is required
        int firstLast = abs(nums[n - 1] - nums[0]);
        maxDiff = max(maxDiff, firstLast);

        return maxDiff;
    }
};


int main(){
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int &num : nums) cin >> num;
	Solution sol;
	int res = sol.maxAdjacentDistance(nums);
	cout << res << endl;
}
