#include <bits/stdc++.h>
using namespace std;
/*
Problem : Minimum in the Rotated Sorted Array or Find the index from where the array is rotated.
Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ or 
Explanation : Given an integer array nums sorted in non-decreasing order, find the starting index of the minimum element.
              Assuming that it does not contain duplicates.
              What is the minimum element? The minimum element is the element from where the array is rotated.
              Example 1: Input: nums = [3,4,5,1,2]
                         Output: 1
                         Explanation: The original array was [1,2,3,4,5] rotated 3 times. So the minimum element is 1.
                How we going to solve this problem?First approach is 
                to use the linear search which will take O(n) time complexity. But we can solve this problem in O(logn) time complexity
                by using the binary search. For the binary search we need to find the pivot element from where the array is rotated.
                For that we need to eliminate the half of the array in each iteration. But which part to be eliminated is the question.
                We'll eliminate the sorted part of the array as the pivot element will be in the unsorted part of the array. But
                there is an edge case where the array is that element is present in the sorted part of the array. So we need to check
                that condition as well. 
                For example : [4,5,1,2,3] -> Here the pivot element is 1. So we need to eliminate the sorted part of the array. But if we do so
                we'll eliminate the 1 as well. So for that we need to hold the value of the minimum element and update it whenever we find the
                minimum element.
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}


