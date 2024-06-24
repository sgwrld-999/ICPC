#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Combination Sum 2
Problem link : https://leetcode.com/problems/combination-sum-ii/
Explanation : Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Approach 1: Pick and Not Pick like the previous problem combination sum. BUt instead of using the same element again we can move to the next element and to store the unique combinations we can use a set.
Approach 2: Recusion transiton means we'll avoid the duplicate combinations by not picking the same element again. We can do this by checking if the current element is same as the previous element and if it is then we'll skip it.

*/
class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, set<vector<int>>& results, vector<int>& currentCombination) {
        if (index == candidates.size()) {
            if (target == 0) {
                results.insert(currentCombination);
            }
            return;
        }
        if (candidates[index] <= target) {
            currentCombination.push_back(candidates[index]);
            findCombinations(index+1, target - candidates[index], candidates, results, currentCombination);
            currentCombination.pop_back();
        }
        findCombinations(index + 1, target, candidates, results, currentCombination);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> results;
        vector<int> currentCombination;
        findCombinations(0, target, candidates, results, currentCombination);
        return vector<vector<int>>(results.begin(), results.end());
    }
};

class Solution2 {
public:
    void findCombinations(int index, int target, vector<int>& candidates, set<vector<int>>& results, vector<int>& currentCombination) {
        if (target == 0) {
            results.insert(currentCombination);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            currentCombination.push_back(candidates[i]);
            findCombinations(i + 1, target - candidates[i], candidates, results, currentCombination);
            currentCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> results;
        vector<int> currentCombination;
        findCombinations(0, target, candidates, results, currentCombination);
        return vector<vector<int>>(results.begin(), results.end());
    }
};

int main() {
    Solution s;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for (auto v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}