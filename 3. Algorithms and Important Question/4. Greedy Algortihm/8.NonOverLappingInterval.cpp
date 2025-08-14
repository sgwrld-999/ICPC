#include <vector>
#include <algorithm>

using namespace std;
/*
Problem name: Non-overlapping Intervals
Problem link: https://leetcode.com/problems/non-overlapping-intervals/
Explanation : Everything is same as N meeting in one room. But this time we have to find the minimum number of intervals to remove to make the intervals non-overlapping.
It'll non-selected meeting in one room.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int lastEndTime = intervals[0][1];
        int count = 1; 
        for (int i = 1; i < intervals.size(); i++) {
            
            if (intervals[i][0] >= lastEndTime) {
                lastEndTime = intervals[i][1];
                count++;
            }
        }

        return n-count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    int res = s.eraseOverlapIntervals(intervals);
    return 0;
}