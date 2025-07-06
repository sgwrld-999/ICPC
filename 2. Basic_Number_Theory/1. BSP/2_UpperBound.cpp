#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the first index where arr[i] > target (smallest index with value greater than target)
 *    - If no such index exists, return -1 or array size (implementation dependent)
 *    - This is the complement to lower bound - helps find insertion points and ranges
 * 
 * 2. **Key Insight**: 
 *    - Upper bound partitions array into: [elements <= target] [elements > target]
 *    - We want the first element of the second partition
 *    - Together with lower bound, can find all occurrences of an element
 * 
 * 3. **Approach**:
 *    - Use modified binary search similar to lower bound
 *    - When arr[mid] > target: this could be answer, search left for smaller index
 *    - When arr[mid] <= target: answer must be to the right
 *    - Key difference: condition is strictly greater than (>) vs greater equal (>=)
 * 
 * 4. **Relationship with Lower Bound**:
 *    - Lower bound finds first occurrence of target (or insertion point)
 *    - Upper bound finds position after last occurrence of target
 *    - Range [lower_bound, upper_bound) contains all occurrences of target
 * 
 * 5. **Edge Cases**:
 *    - All elements <= target: return -1 (no element greater than target)
 *    - All elements > target: return index 0
 *    - Target smaller than all elements: return index 0
 *    - Empty array: return -1
 * 
 * 6. **Complexity**:
 *    - Time: O(log n) - binary search
 *    - Space: O(1) - constant extra space
 */

class MySolution {
public:
    int upperBound(vector<int>& ipVec, int low, int high, int target) {
        int ans = -1;
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            if (ipVec[mid] > target) {
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
    int result = solution.upperBound(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Upper Bound : " << result << endl;
    return 0;
}
