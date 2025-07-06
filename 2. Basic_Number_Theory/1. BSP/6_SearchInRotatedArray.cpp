#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Search target in rotated sorted array (e.g., [4,5,6,7,0,1,2])
 *    - Array was originally sorted, then rotated at unknown pivot
 *    - Need O(log n) solution - can't use linear search
 *    - No duplicates in array (important constraint)
 * 
 * 2. **Key Insight**: 
 *    - Although entire array isn't sorted, one half is always sorted
 *    - At any mid point, either left half [low...mid] or right half [mid...high] is sorted
 *    - Can determine which half is sorted by comparing boundary elements
 *    - Once we know sorted half, can check if target lies in that range
 * 
 * 3. **Critical Binary Search Modification**:
 *    - Standard binary search assumes entire array is sorted
 *    - Here: identify sorted half, check if target is in that range
 *    - If target in sorted half: search that half normally
 *    - If target not in sorted half: search the other half
 * 
 * 4. **Approach**:
 *    - Check nums[mid] == target (lucky case)
 *    - Determine sorted half: if nums[low] ≤ nums[mid], left half is sorted
 *    - For sorted left half: if nums[low] ≤ target ≤ nums[mid], search left
 *    - Otherwise search right
 *    - Similar logic for sorted right half
 * 
 * 5. **Why This Works**:
 *    - Rotation creates exactly one "break" point where large number is followed by small
 *    - This break can only exist in at most one half at any mid point
 *    - The other half maintains its sorted property
 * 
 * 6. **Edge Cases**:
 *    - Array not rotated (rotation by 0): normal binary search
 *    - Single element: direct comparison
 *    - Target at rotation point (smallest/largest element)
 *    - Target doesn't exist: return -1
 * 
 * 7. **Complexity**:
 *    - Time: O(log n) - binary search with constant time decisions
 *    - Space: O(1) - constant extra space
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target) return mid; // If the mid element is the target element then return the index
            else if(nums[low]<=nums[mid]){ // If the left half is sorted then check if the target element is in the left half or not
                if(nums[low] <= target && nums[mid] >= target) high = mid - 1; // If the target element is in the left half then eleminate the right half
                else low = mid + 1; // If the target element is not in the left half then eleminate the left half
            }else{ // If the right half is sorted then check if the target element is in the right half or not
                if(nums[mid] <= target && nums[high] >= target) low = mid + 1; // If the target element is in the right half then eleminate the left half
                else high = mid - 1;// If the target element is not in the right half then eleminate the right half
            }
        }

        return -1;// If the target element is not found then return -1
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
    int result = solution.search(ipVec, target); 
    cout << "Required Element ans :  [" << result << "]"<< endl;
    return 0;
}
