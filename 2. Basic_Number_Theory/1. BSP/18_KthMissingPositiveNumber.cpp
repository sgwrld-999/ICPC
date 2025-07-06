#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find the kth missing positive integer from a sorted array
 *    - Missing numbers are positive integers not present in the array
 *    - Example: [2,3,7,11,13], k=5 → missing: [1,4,5,6,8,...] → 5th missing is 8
 * 
 * 2. **Key Insight**: 
 *    - Brute force: enumerate all missing numbers - O(n + k) time, O(k) space
 *    - Binary search: find position where exactly k numbers are missing - O(log n) time
 *    - At position i, missing count = arr[i] - (i + 1) - offset
 * 
 * 3. **Binary Search Approach**:
 *    - For each position i, calculate how many numbers are missing up to arr[i]
 *    - Missing count at i = arr[i] - expected_value_at_i
 *    - Expected value at position i = i + 1 + starting_offset
 *    - Find position where missing count transitions around k
 * 
 * 4. **Missing Count Formula**:
 *    - If array started from 1: expected[i] = i + 1
 *    - If array starts from arr[0]: expected[i] = i + arr[0]
 *    - Missing count = arr[i] - expected[i]
 *    - This tells us how many numbers are missing before arr[i]
 * 
 * 5. **Binary Search Logic**:
 *    - If missing_count < k: kth missing is after position mid (search right)
 *    - If missing_count >= k: kth missing is before or at position mid (search left)
 *    - Final position gives us range where kth missing number lies
 * 
 * 6. **Edge Cases**:
 *    - k smaller than any missing numbers: might be before array starts
 *    - k larger than all missing numbers in array range: extrapolate beyond array
 *    - Array starts from 1: no offset needed
 *    - Consecutive array: no missing numbers within range
 * 
 * 7. **Simpler Approach (Brute Force)**:
 *    - Generate all missing numbers by comparing with expected sequence
 *    - More intuitive but uses O(k) extra space
 *    - Better for small k or when simplicity is preferred
 * 
 * 8. **Complexity**:
 *    - Binary Search: O(log n) time, O(1) space
 *    - Brute Force: O(n + k) time, O(k) space
 */

/*
Logic ExplanationInitialize Variables:missingEle: A vector to store the missing elements.current: A variable initialized to the first element of the array, representing the expected value in the sequence.Iterate through the array:For each element in the array, check if there are any missing elements between the current value and the array element.Use a while loop to add all missing elements to missingEle until current catches up to the array element.Boundary Check:After collecting all missing elements, check if the number of missing elements is less than k. If so, return -1 since there aren't enough missing elements.Return k-th Missing Element:If there are enough missing elements, return the k-th missing element from missingEle.ExampleConsider the array a[] = {2, 3, 7, 11, 13} and k = 5.Dry RunInitial Setup:a = {2, 3, 7, 11, 13}n = 5k = 5missingEle = []current = 2Iteration:i = 0:current = 2a[0] = 2current matches a[0], increment current to 3.i = 1:current = 3a[1] = 3current matches a[1], increment current to 4.i = 2:current = 4a[2] = 7current (4) is less than a[2] (7), add 4, 5, and 6 to missingEle.missingEle = {4, 5, 6}Increment current to 7.i = 3:current = 7a[3] = 11current (7) matches a[3], increment current to 8.current (8) is less than a[3] (11), add 8, 9, and 10 to missingEle.missingEle = {4, 5, 6, 8, 9, 10}Increment current to 11.i = 4:current = 11a[4] = 13current matches a[4], increment current to 12.current (12) is less than a[4] (13), add 12 to missingEle.missingEle = {4, 5, 6, 8, 9, 10, 12}Increment current to 13.Boundary Check:missingEle contains 7 elements: {4, 5, 6, 8, 9, 10, 12}k = 5The 5th missing element is 9 (index k-1 which is 4).
*/
int KthMissingElement(int a[], int n, int k)
{
    vector<int> missingEle;
    int current = a[0];

    for(int i = 0; i < n; ++i)
    {
        while(current < a[i])
        {
            missingEle.push_back(current);
            current++;
        }
        current++;
    }

    if(k > missingEle.size())
    {
        return -1;
    }

    return missingEle[k-1];
}
int KthMissingElementBinarySeach(int arr[], int n, int K) {
    int low = 0;
    int high = n - 1;
    int start = arr[0] - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] - (mid + 1 + start) == K && arr[mid] - arr[mid - 1] != 1) {
            return arr[mid] - 1;
        } else if (mid == n - 1 && arr[mid] - n == K) {
            return arr[mid] - 1;
        } else if (mid + 1 + start == arr[mid]) {
            low = mid + 1;
        } else if (arr[mid] - (mid + 1 + start) < K) {
            low = mid + 1;
        } else if (arr[mid] - (mid + 1 + start) >= K) {
            high = mid;
        }

        if (mid == low && low == high) {
            break;
        }
    }

    if (arr[low] - (low + 1 + start) > K) {
        for (int p = arr[low]; p > arr[low - 1]; --p) {
            if (p - (low + start) == K) {
                return p;
            }
        }
    }
    return -1;
}


int main() {
    int a[] = {2, 3, 7, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    cout << KthMissingElement(a, n, k) << endl;  // Output should be 9
    return 0;
}
