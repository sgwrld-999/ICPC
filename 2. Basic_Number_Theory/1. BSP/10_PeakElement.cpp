#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Find any peak element in an array (element greater than its neighbors)
 *    - Peak element: arr[i] > arr[i-1] && arr[i] > arr[i+1]
 *    - Array boundaries are considered as negative infinity
 *    - At least one peak is guaranteed to exist
 * 
 * 2. **Key Insight**: 
 *    - Think of array as a mountain range - there's always at least one peak
 *    - If we're on an ascending slope (arr[mid] < arr[mid+1]), peak must be ahead
 *    - If we're on a descending slope (arr[mid] > arr[mid+1]), peak must be behind
 *    - We can eliminate half the array at each step using this property
 * 
 * 3. **Why Binary Search Works**:
 *    - Unlike standard binary search, we don't need the array to be sorted
 *    - We use the slope direction to decide which half contains a peak
 *    - Since boundaries are -∞, we're guaranteed to find a peak
 * 
 * 4. **Approach**:
 *    - Handle edge cases: single element, first/last element peaks
 *    - Use binary search on middle elements (indices 1 to n-2)
 *    - If arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]: found peak
 *    - If arr[mid] < arr[mid+1]: ascending slope, search right half
 *    - Else: descending slope, search left half
 * 
 * 5. **Edge Cases**:
 *    - Single element: always a peak
 *    - First element > second element: first is peak
 *    - Last element > second last element: last is peak
 *    - All elements same: any element is peak
 * 
 * 6. **Complexity**:
 *    - Time: O(log n) - binary search
 *    - Space: O(1) - constant extra space
 */


//Leetcode 162. Find Peak Element
class Solution {
public:
    int peakElementIndex(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {return mid;}
        else if(arr[mid] > arr[mid-1]) low = mid + 1;
        else high = mid - 1;
        }
    return -1;
    }
};

//GFG : Peak element : https://www.geeksforgeeks.org/problems/peak-element/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
int main(int argc, char const *argv[])
{
    vector<int> arr;
    int sizeOfVec ;
    cout << "Enter the size of ipVec : " ;
    cin >> sizeOfVec ;
    for (int i = 0; i < sizeOfVec ; i++)
    {
        int temp ;
        cin >> temp ;
        arr.push_back(temp);
    }
    Solution obj;
    int resultantIndex = obj.peakElementIndex(arr);
    cout << "The peak is at the " << resultantIndex << " index in the array.";
    return 0;
}

/*
Test Cases:

input :
    5
    1 2 5 4 5
*/