#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find median of two sorted arrays in O(log(m+n)) time
 *    - Median: middle value in sorted order (or average of two middle values)
 *    - Cannot simply merge arrays as that would be O(m+n) time
 * 
 * 2. **Key Insight**: 
 *    - Use binary search on the smaller array to find the correct partition
 *    - Partition both arrays such that left halves have same count as right halves
 *    - Elements in left partition ≤ elements in right partition
 *    - Median comes from the boundary elements of this partition
 * 
 * 3. **Optimal Approach (Binary Search)**:
 *    - Binary search on smaller array (say array1) for partition point
 *    - If we take 'i' elements from array1, take '(m+n+1)/2 - i' from array2
 *    - Check if partition is valid: maxLeft1 ≤ minRight2 && maxLeft2 ≤ minRight1
 *    - If maxLeft1 > minRight2: taking too many from array1, search left
 *    - If maxLeft2 > minRight1: taking too few from array1, search right
 * 
 * 4. **Current Implementation (Suboptimal)**:
 *    - Simple merge and sort approach: O((m+n)log(m+n)) time
 *    - This violates the O(log(m+n)) requirement but is easier to understand
 *    - Good for learning but should implement binary search version for interviews
 * 
 * 5. **Edge Cases**:
 *    - One array is empty: median is from the other array
 *    - Arrays have very different sizes
 *    - Total size is even vs odd (affects median calculation)
 *    - All elements of one array < all elements of other array
 * 
 * 6. **Complexity**:
 *    - Current: O((m+n)log(m+n)) time, O(m+n) space
 *    - Optimal: O(log(min(m,n))) time, O(1) space
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        vector<int> mergedArray;
        mergedArray.reserve(array1.size() + array2.size());

        mergedArray.insert(mergedArray.end(), array1.begin(), array1.end());
        mergedArray.insert(mergedArray.end(), array2.begin(), array2.end());

        sort(mergedArray.begin(), mergedArray.end());

        int totalSize = mergedArray.size();
        if (totalSize % 2 == 0) {
            return (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
        } else {
            return mergedArray[totalSize / 2];
        }
    }
};