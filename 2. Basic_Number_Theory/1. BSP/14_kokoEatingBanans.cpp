#include <bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Koko eats bananas at rate K bananas/hour from piles
 *    - Must finish all bananas within H hours
 *    - Find minimum eating speed K to achieve this
 *    - If pile has < K bananas, eat all and waste rest of hour
 * 
 * 2. **Key Insight**: 
 *    - This is optimization problem: minimize K subject to constraint (total time ≤ H)
 *    - Search space: K ranges from 1 to max(piles)
 *    - If K works, any larger K also works (monotonic property)
 *    - Perfect candidate for binary search on answer
 * 
 * 3. **Why Binary Search on Answer**:
 *    - We're not searching in array, but searching for optimal value in range
 *    - Function f(K) = "can finish in H hours with speed K" is monotonic
 *    - Want smallest K where f(K) = true
 *    - This is exactly lower bound problem in disguise
 * 
 * 4. **Approach**:
 *    - Range: low = 1, high = max(piles)
 *    - For each mid (candidate speed), calculate total time needed
 *    - Time for pile[i] = ceil(pile[i] / speed) hours
 *    - If total_time ≤ H: try smaller speed (search left)
 *    - If total_time > H: need larger speed (search right)
 * 
 * 5. **Implementation Details**:
 *    - Use ceil((double)pile / (double)speed) to handle integer division correctly
 *    - Total time = sum of ceiling divisions for all piles
 *    - Return the smallest valid speed found
 * 
 * 6. **Edge Cases**:
 *    - H = number of piles: minimum speed is max(piles)
 *    - Single pile: need exactly ceil(pile/H) speed
 *    - All piles equal: straightforward calculation
 * 
 * 7. **Complexity**:
 *    - Time: O(n * log(max(piles))) - binary search with O(n) validation
 *    - Space: O(1) - constant extra space
 */
class Solution {
public:
    int calculateTotalHours(vector<int>& piles, int bananasPerHour) {
        int totalHours = 0;
        for (auto pile : piles) {
            totalHours += ceil((double)pile / (double)bananasPerHour);
        }
        return totalHours;
    }

    int findMinBananasPerHour(int N, vector<int>& piles, int H) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxPile;
        int totalHours = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            totalHours = calculateTotalHours(piles, mid);

            if (totalHours <= H) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> piles;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            piles.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.findMinBananasPerHour(n, piles, h);
        cout << "\n";
    }
    return 0;
}
/*
Test cases: 
Input :
2
4
3 6 7 11
8
5
30 11 23 4 20
6
Output :
4
23

*/