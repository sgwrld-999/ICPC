#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Split array into k non-empty subarrays to minimize the maximum sum among all subarrays
 *    - This is a classic "minimize the maximum" optimization problem
 *    - Need to find optimal way to place k-1 splits in the array
 * 
 * 2. **Key Insight**: 
 *    - Direct approach (try all possible splits) is exponential
 *    - Binary search on answer: "Can we split array into k parts with max sum ≤ target?"
 *    - Search space: max element ≤ answer ≤ sum of all elements
 * 
 * 3. **Binary Search on Answer Pattern**:
 *    - Lower bound: max(arr) (at least one subarray contains the largest element)
 *    - Upper bound: sum(arr) (worst case: all elements in one subarray)
 *    - For each candidate max sum, check if k splits are possible
 * 
 * 4. **Validation Function (Greedy)**:
 *    - Try to form subarrays greedily with sum ≤ target
 *    - Start new subarray when adding next element exceeds target
 *    - Count total subarrays formed
 *    - If count ≤ k, then target is achievable
 * 
 * 5. **Why Greedy Works for Validation**:
 *    - If we can form subarrays with max sum ≤ target, greedy gives optimal count
 *    - No benefit in starting new subarray early - only increases count
 *    - Greedy minimizes number of subarrays needed
 * 
 * 6. **Implementation Details**:
 *    - Binary search: if validation succeeds, try smaller max sum
 *    - If validation fails, increase max sum
 *    - Return the smallest achievable maximum sum
 * 
 * 7. **Edge Cases**:
 *    - k = 1: return sum of entire array
 *    - k = array length: return maximum element
 *    - Single element array: return that element
 * 
 * 8. **Complexity**:
 *    - Time: O(n * log(sum - max)) - binary search with O(n) validation
 *    - Space: O(1) - constant extra space
 */

class Solution {
public:
    // Check if we can split array into at most k subarrays with max sum <= maxSum
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int subarrays = 1;
        int currentSum = 0;
        
        for (int num : nums) {
            if (num > maxSum) return false; // Single element exceeds limit
            
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                // Start new subarray
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (canSplit(nums, k, mid)) {
                high = mid; // Try to find smaller maximum sum
            } else {
                low = mid + 1; // Need larger maximum sum
            }
        }
        
        return low;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;
    
    Solution obj;
    cout << "Minimum possible maximum sum: " << obj.splitArray(nums, k) << endl;
    
    return 0;
}

/*
Test Cases:
Input:
5
7 2 5 10 8
2
Output: 18
Explanation: Split as [7,2,5] and [10,8] with max sums 14 and 18 respectively.

Input:
4
1 2 3 4
2
Output: 6
Explanation: Split as [1,2,3] and [4] with max sums 6 and 4 respectively.
*/
