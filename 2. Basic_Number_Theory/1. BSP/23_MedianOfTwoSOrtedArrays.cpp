#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Median of Two Sorted Arrays
Problem link : https://leetcode.com/problems/median-of-two-sorted-arrays/
Explanation  : Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
               The overall run time complexity should be O(log (m+n)).
               Example 1:
               Input: nums1 = [1,3], nums2 = [2]
               Output: 2.00000
               Explanation: merged array = [1,2,3] and median is 2.
               Approach 1 : 
      x         1. Merge the two arrays.
               2. Sort the merged array.
               3. If the size of the merged array is even, return the average of the middle two elements.
               4. If the size of the merged array is odd, return the middle element.
               Time Complexity : O((m+n)log(m+n))
               Space Complexity : O(m+n)

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) {
        vector<int> mergedArray;
        mergedArray.reserve(array1.size() + array2.size());

        mergedArray.insert(mergedArray.end(), array1.begin(), array1.end());
        mergedArray.insert(mergedArray.end(), array2.begin(), array2.end());

        sort(mergedArray.begin(), mergedArray.end());

        int totalSize = mergedArray.size();
        if (totalSize % 2 == 0) {
            return (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
        } else {
            return mergedArray[totalSize / 2];
        }
    }
};