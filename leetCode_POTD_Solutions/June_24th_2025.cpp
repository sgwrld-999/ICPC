#include<iostream>
#include<vector>
using namespace std;

/*
Solution: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/solutions/6880642/find-k-distant-indices-sliding-influence-yqqs
*/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        
        vector<int> index;

        // Step 1: Collect all indices where nums[i] == key
        for (int i = 0 ; i < n ; i++) {
            if (key == nums[i]) index.push_back(i);
        }

        // Step 2: If no key found, return empty vector
        if (index.size() == 0) return vector<int>{};

        // Step 3: Mark indices that are within distance k of any key index
        vector<bool> ansOrNot(n, false);

        for (int i = 0 ; i < index.size(); i++) {
            for (int j = 0 ; j < n ; j++) {
                if (abs(index[i] - j) <= k) {
                    ansOrNot[j] = true; 
                }
            }
        }

        // Step 4: Collect the marked indices into the answer
        vector<int> ans;
        for (int i = 0 ; i < n ; i++) {
            if (ansOrNot[i]) ans.push_back(i);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findKDistantIndices(const vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> withinDistance(n, false);

        // Step 1: Find all indices where nums[i] == key
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                // Step 2: Mark all indices within distance k
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; j++) {
                    withinDistance[j] = true;
                }
            }
        }

        // Step 3: Collect all indices that are marked
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (withinDistance[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
