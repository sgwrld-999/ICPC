#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the first index where arr[i] >= target (smallest index satisfying condition)
 *    - If no such index exists, return -1 or array size (implementation dependent)
 *    - This is fundamental for range queries and insertion point finding
 * 
 * 2. **Key Insight**: 
 *    - Lower bound partitions array into: [elements < target] [elements >= target]
 *    - We want the first element of the second partition
 *    - Binary search can find this boundary efficiently
 * 
 * 3. **Approach**:
 *    - Use modified binary search that tracks potential answer
 *    - When arr[mid] >= target: this could be answer, but check left for smaller index
 *    - When arr[mid] < target: answer must be to the right
 *    - Always update answer when condition is satisfied and continue searching left
 * 
 * 4. **Critical Difference from Standard Binary Search**:
 *    - Don't stop when condition is met - keep searching for leftmost occurrence
 *    - Track the best answer found so far
 *    - Search left when condition is satisfied (to find smaller valid index)
 * 
 * 5. **Edge Cases**:
 *    - All elements < target: return -1 (no valid index)
 *    - All elements >= target: return index 0
 *    - Target larger than all elements: return -1
 *    - Empty array: return -1
 * 
 * 6. **Complexity**:
 *    - Time: O(log n) - binary search
 *    - Space: O(1) - only using constant extra space
 */

/*
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index as ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/
class MySolution {
public:
    int lowerBound(vector<int>& ipVec, int low, int high, int target) {
        int ans = -1;
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            if (ipVec[mid] >= target) {
                ans = mid ;
                high = mid - 1 ;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    MySolution solution;
    int target;
    cin >> target;
    int result = solution.lowerBound(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Lower Bound : " << result << endl;
    return 0;
}
