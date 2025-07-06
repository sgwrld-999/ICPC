#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the nth root of integer m: find x such that x^n = m
 *    - If exact nth root doesn't exist, return -1
 *    - Need to avoid using built-in pow() or root functions
 * 
 * 2. **Key Insight**: 
 *    - Similar to square root problem, but with nth power instead of square
 *    - Search space: x ranges from 1 to m (can optimize upper bound)
 *    - Need to check if x^n equals m exactly
 * 
 * 3. **Binary Search Approach**:
 *    - Range: low = 1, high = m (can optimize to m^(1/n) approximation)
 *    - For each mid, calculate mid^n and compare with m
 *    - If mid^n = m: found exact nth root
 *    - If mid^n < m: search right half
 *    - If mid^n > m: search left half
 * 
 * 4. **Power Calculation Challenge**:
 *    - Computing mid^n directly can cause overflow for large values
 *    - Need safe power calculation with overflow detection
 *    - Can use logarithms or iterative multiplication with bounds checking
 * 
 * 5. **Optimization**:
 *    - Upper bound can be min(m, 2) for most practical cases
 *    - For n > 1, nth root of m is always ≤ sqrt(m)
 *    - Early termination when mid^n exceeds m
 * 
 * 6. **Edge Cases**:
 *    - m = 0: return 0 (0^n = 0 for n > 0)
 *    - m = 1: return 1 (1^n = 1 for any n)
 *    - n = 1: return m (m^1 = m)
 *    - No exact nth root exists: return -1
 * 
 * 7. **Complexity**:
 *    - Time: O(log m * log n) - binary search with power calculation
 *    - Space: O(1) - constant extra space
 */

/*
Problem name : Nth root of an integer
https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
*/

class Solution {
public:
    // Helper function to calculate power with overflow protection
    long long power(int base, int exp, int limit) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            if (result > limit / base) return limit + 1; // Overflow protection
            result *= base;
        }
        return result;
    }
    
    int NthRoot(int n, int m) {
        if (m == 0) return 0;
        if (m == 1) return 1;
        if (n == 1) return m;
        
        int low = 1, high = m;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long midPowerN = power(mid, n, m);
            
            if (midPowerN == m) {
                return mid;
            } else if (midPowerN < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1; // No exact nth root exists
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution obj;
        cout << obj.NthRoot(n, m) << endl;
    }
    return 0;
}