#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int totalSubSets = pow(2, n);

        for (int i = 0; i < totalSubSets; i++) {
            vector<int> list;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }

        return ans;
    }
};