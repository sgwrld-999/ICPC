#include<bits/stdc++.h>
using namespace std;
/*
1. Problem Name: Largest Rectangle in Histogram

2. **Problem Link:** [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

3. **Explanation:**
   - **Brute Force Approach:**
     The brute force approach to solving the "Largest Rectangle in Histogram" problem involves checking every possible pair of bars and calculating the area of the rectangle formed between them. For each pair, the height of the rectangle is the minimum height of the bars between and including the two bars being considered. The width is the difference between the indices of these bars plus one. This approach has a time complexity of O(n^2), which can be too slow for large inputs.

   - **Examples:**
     Consider the histogram represented by the heights `[2, 1, 5, 6, 2, 3]`. The largest rectangle can be formed between the bars of heights 5 and 6, and the area is 10 (height 5 * width 2).

   - **Dry Run of the Code with an Example:**
     Let's use the heights array `[2, 1, 5, 6, 2, 3]` to dry run the optimized code provided:

     **Initialization:**
     - `n = 6` (length of the array)
     - `leftSmall = [0, 0, 0, 0, 0, 0]`
     - `rightSmall = [0, 0, 0, 0, 0, 0]`
     - `stack = []`
     - `maxA = INT_MIN`

     **Calculate the nearest smaller to left:**
     - For `i = 0`: stack is empty, so `leftSmall[0] = 0`. Push 0 to stack.
     - For `i = 1`: Pop 0 from stack because `heights[0] >= heights[1]`. Stack is empty, so `leftSmall[1] = 0`. Push 1 to stack.
     - For `i = 2`: `heights[1] < heights[2]`, so `leftSmall[2] = 2`. Push 2 to stack.
     - For `i = 3`: `heights[2] < heights[3]`, so `leftSmall[3] = 3`. Push 3 to stack.
     - For `i = 4`: Pop 3, then 2 from stack because `heights[3]` and `heights[2] >= heights[4]`. Stack is now [1], so `leftSmall[4] = 2`. Push 4 to stack.
     - For `i = 5`: `heights[4] < heights[5]`, so `leftSmall[5] = 5`. Push 5 to stack.

     **Clear the stack to reuse for the right calculation.**

     **Calculate the nearest smaller to right:**
     - For `i = 5`: stack is empty, so `rightSmall[5] = 6`. Push 5 to stack.
     - For `i = 4`: `heights[5] >= heights[4]`, so pop 5. Stack is empty, so `rightSmall[4] = 6`. Push 4 to stack.
     - For `i = 3`: `heights[4] >= heights[3]`, so pop 4. Stack is empty, so `rightSmall[3] = 6`. Push 3 to stack.
     - For `i = 2`: `heights[3] >= heights[2]`, so pop 3. Stack is now [4], so `rightSmall[2] = 4`. Push 2 to stack.
     - For `i = 1`: Pop 2, 4, 3, 5 because all are greater than `heights[1]`. Stack is empty, so `rightSmall[1] = 6`. Push 1 to stack.
     - For `i = 0`: `heights[1] >= heights[0]`, so pop 1. Stack is empty, so `rightSmall[0] = 6`. Push 0 to stack.

     **Calculate the maximum area:**
     - Iterate over each index `i` from 0 to 5:
       - Calculate area for each bar as `(rightSmall[i] - leftSmall[i]) * heights[i]`.
       - Update `maxA` if the current area is larger.

     The maximum area found is 10 for the bar at index 2 with height 5 and width 2 (indices 2 to 3).

This optimized approach uses a stack to efficiently find the nearest smaller bars on both sides for each bar, allowing us to calculate the largest rectangle in O(n) time.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        stack<int> st;

        // Calculate the nearest smaller to left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftSmall[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear the stack to reuse for the right calculation
        while (!st.empty()) st.pop();

        // Calculate the nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate the maximum area
        int maxA = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, (rightSmall[i] - leftSmall[i]) * heights[i]);
        }

        return maxA;
    }
};
