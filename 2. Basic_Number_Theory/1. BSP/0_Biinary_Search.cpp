#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the index of a target element in a sorted array.
 *    - If element doesn't exist, return -1.
 *    - This is the fundamental binary search problem.
 * 
 * 2. **Key Insight**: 
 *    - Since array is sorted, we can eliminate half the search space at each step
 *    - Compare middle element with target to decide which half to search next
 *    - This gives us O(log n) time complexity instead of O(n) linear search
 * 
 * 3. **Approach**:
 *    - Maintain two pointers: low (start) and high (end) of search range
 *    - Calculate mid = low + (high - low) / 2 to avoid overflow
 *    - If arr[mid] == target: found, return mid
 *    - If arr[mid] < target: search right half (low = mid + 1)
 *    - If arr[mid] > target: search left half (high = mid - 1)
 *    - Continue until low > high (element not found)
 * 
 * 4. **Implementation Choices**:
 *    - Iterative: O(1) space, easier to debug
 *    - Recursive: O(log n) space due to call stack, more elegant
 * 
 * 5. **Edge Cases**:
 *    - Empty array: return -1
 *    - Single element: base case for recursion
 *    - Target not in array: exhausted search space
 *    - Target at boundaries: first or last element
 * 
 * 6. **Complexity**:
 *    - Time: O(log n) - halving search space each iteration
 *    - Space: O(1) iterative, O(log n) recursive
 */

class Solution{
public:
    int iterativeBS(vector<int> ipVec,int target){
        int low = 0;
        int high = ipVec.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(ipVec[mid] == target)
                return mid;
            else if (ipVec[mid] < target)
                low = mid + 1 ;
            else 
                high = mid - 1;
        }
        return -1;
    }

    int recursiveBS(vector<int> ipVec,int low,int high,int target){
        if(low > high)
            return -1;
        int mid = low + (high - low) / 2 ;
        if(ipVec[mid] == target)
            return mid;
        else if(ipVec[mid] < target)
            return recursiveBS(ipVec,mid+1,high,target);
        else 
            return recursiveBS(ipVec,low,mid-1,target);
    }
}; 

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    int target;
    cin >> target;
    Solution obj;
    int result = obj.recursiveBS(ipVec,0,sizeOfIpVec -1,target);
    cout << "The target element is at index: " << result << endl;
    return 0;
}