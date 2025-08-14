#include<bits/stdc++.h>
using namespace std;
/*
Problem name: Insertion Sort
Problem link LeeCode : https://leetcode.com/problems/sort-an-array/
Explanation : 
1. We will pick the element from the unsorted array and place it at the correct position in the sorted array.
2. We will repeat the above step for all the elements in the array.
Time complexity : O(n^2)
Space complexity : O(1)

Dry run example:
arr = [9,1,5,6,2,3]

Step 1: Start from the second element (arr[1] = 1)

Compare 1 with the previous elements.
1 is less than 9, so move 9 to the right.
New array: [1, 9, 5, 6, 2, 3]
Step 2: Move to the third element (arr[2] = 5)

Compare 5 with the previous elements.
5 is less than 9, so move 9 to the right.
5 is greater than 1, so place 5 between 1 and 9.
New array: [1, 5, 9, 6, 2, 3]
Step 3: Move to the fourth element (arr[3] = 6)

Compare 6 with the previous elements.
6 is less than 9, so move 9 to the right.
6 is greater than 5, so place 6 between 5 and 9.
New array: [1, 5, 6, 9, 2, 3]
Step 4: Move to the fifth element (arr[4] = 2)

Compare 2 with the previous elements.
2 is less than 9, move 9 to the right.
2 is less than 6, move 6 to the right.
2 is less than 5, move 5 to the right.
2 is greater than 1, so place 2 between 1 and 5.
New array: [1, 2, 5, 6, 9, 3]
Step 5: Move to the sixth element (arr[5] = 3)

Compare 3 with the previous elements.
3 is less than 9, move 9 to the right.
3 is less than 6, move 6 to the right.
3 is less than 5, move 5 to the right.
3 is greater than 2, so place 3 between 2 and 5.
New array: [1, 2, 3, 5, 6, 9]
Final Sorted Array
[1, 2, 3, 5, 6, 9]

This is how the insertion sort algorithm sorts the array [9, 1, 5, 6, 2, 3] into [1, 2, 3, 5, 6, 9] through a series of insertions into the portion of the array that is already sorted.
*/
vector<int> InsertionSortArray(vector<int>& nums) {
int n = nums.size();
for(int step = 1; step < n; step++) {
    int key = nums[step];
    int j = step - 1;

    while(j >= 0 && key < nums[j]) {
        nums[j + 1] = nums[j];
        j--;
    }
    nums[j + 1] = key;
}
return nums;
}