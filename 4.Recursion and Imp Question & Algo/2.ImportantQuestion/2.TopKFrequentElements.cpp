#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            vec.push_back({it.second, it.first});
        }

        // Sort by frequency in descending order
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}