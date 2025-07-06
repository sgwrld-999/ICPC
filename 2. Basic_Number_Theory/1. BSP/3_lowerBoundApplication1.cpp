#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find index of target in sorted array, or insertion position if not found
 *    - Return index where target should be inserted to maintain sorted order
 *    - This is exactly the definition of lower bound!
 * 
 * 2. **Key Insight**: 
 *    - This problem IS lower bound in disguise
 *    - Lower bound = first position where we can insert target to keep array sorted
 *    - If target exists: return its index
 *    - If target doesn't exist: return insertion point
 * 
 * 3. **Connection to Lower Bound**:
 *    - Lower bound finds first index i where arr[i] >= target
 *    - If arr[i] == target: target found at index i
 *    - If arr[i] > target: target should be inserted at index i
 *    - Perfect match for this problem's requirements
 * 
 * 4. **Approach**:
 *    - Use binary search to find insertion position
 *    - When nums[mid] == target: found exact position
 *    - When nums[mid] > target: search left (target should be inserted before mid)
 *    - When nums[mid] < target: search right (target should be inserted after mid)
 *    - Return the final insertion position
 * 
 * 5. **Implementation Choice**:
 *    - Recursive implementation shown (elegant but O(log n) space)
 *    - Iterative version would be O(1) space
 *    - Both approaches return 'low' when search space exhausted
 * 
 * 6. **Edge Cases**:
 *    - Target smaller than all elements: insert at index 0
 *    - Target larger than all elements: insert at end (index = size)
 *    - Target equals existing element: return its index
 *    - Empty array: insert at index 0
 * 
 * 7. **Complexity**:
 *    - Time: O(log n) - binary search
 *    - Space: O(log n) recursive, O(1) iterative
 */

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


int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    Solution solution;
    int target;
    cin >> target;
    int result = solution.searchInsert(ipVec, target);
    cout << "Index : " << result << endl;
    return 0;
}