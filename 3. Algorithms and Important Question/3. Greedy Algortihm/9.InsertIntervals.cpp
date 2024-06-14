#include <bits/stdc++.h>
using namespace std;
/*
Problem name    : Insert Intervals
Problem link    : https://leetcode.com/problems/insert-interval/
Problem Statement: Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
Explanation : 
    Example 1:
    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
    
    Example 2:
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    In this we'll sdivide the intervals in three parts:
    1. Intervals that are before the newInterval.
    2. Intervals that are overlapping with the newInterval.
    3. Intervals that are after the newInterval.
    We'll merge the overlapping intervals with the newInterval and push them in the ans vector.
    Finally we'll push the remaining intervals in the ans vector.
    Return the ans vector.

*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // Intervals that are before the newInterval.
        /*
        How to find it?
        If the end of the current interval is less than the start of the newInterval, then it is before the newInterval.
        */
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // Intervals that are overlapping with the newInterval.
        /*
        How to find it?
        If the start of the current interval is less than or equal to the end of the newInterval, then it is overlapping with the newInterval.
        For the starting of the newInterval, we'll take the minimum of the start of the current interval and the start of the newInterval.
        For the ending of the newInterval, we'll take the maximum of the end of the current interval and the end of the newInterval.
        */

        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval); 
        
        // Intervals that are after the newInterval.
        /*
        How to find it?
        If the start of the current interval is greater than the end of the newInterval, then it is after the newInterval.
        */
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};