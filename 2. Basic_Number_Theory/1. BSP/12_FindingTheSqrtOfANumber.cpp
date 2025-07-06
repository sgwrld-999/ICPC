#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the floor of square root of a given number x
 *    - If x is a perfect square, return exact square root
 *    - If not, return largest integer whose square ≤ x
 *    - Need to avoid using built-in sqrt() function
 * 
 * 2. **Key Insight**: 
 *    - Numbers 1 to n can be partitioned by their square roots:
 *      [1], [2,3], [4,5,6,7,8], [9,10,...,15], [16,17,...,24], ...
 *    - For any number x, its floor sqrt lies in range [1, x]
 *    - We can binary search this range to find the answer
 * 
 * 3. **Why Binary Search Works**:
 *    - Search space is monotonic: if i² ≤ x, then all j² where j < i also ≤ x
 *    - We want the largest i such that i² ≤ x
 *    - This is essentially finding upper bound in the sequence of squares
 * 
 * 4. **Approach**:
 *    - Set search range: low = 1, high = x
 *    - Calculate mid and check mid² vs x
 *    - If mid² = x: exact square root found
 *    - If mid² < x: answer could be mid, but check if larger exists (search right)
 *    - If mid² > x: mid is too large, search left
 *    - Keep track of best valid answer (largest mid where mid² ≤ x)
 * 
 * 5. **Optimization Note**:
 *    - Can optimize high = x/2 for x > 4, since sqrt(x) ≤ x/2 for x > 4
 *    - Prevents overflow issues with large numbers
 * 
 * 6. **Edge Cases**:
 *    - x = 0 or x = 1: return x itself
 *    - Perfect squares: return exact square root
 *    - Large numbers: ensure mid * mid doesn't overflow
 * 
 * 7. **Complexity**:
 *    - Time: O(log x) - binary search
 *    - Space: O(1) - constant extra space
 */

class Solution {
public:
    long long int floorSqrt(long long int x) 
    {
        // Base case
        if (x == 0 || x == 1) return x;

        long long int low = 1;
        long long int high = x;
        long long int ans = 0;

        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            long long int sqrtx = mid * mid;

            if (sqrtx == x) return mid;
            else if (sqrtx < x) {
                low = mid + 1;
                ans = mid;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int x;
        cin >> x;
        Solution obj;
        cout << obj.floorSqrt(x) << endl;
    }
    return 0;
}
/*
Testcase : 
1
5
Output : 2

*/