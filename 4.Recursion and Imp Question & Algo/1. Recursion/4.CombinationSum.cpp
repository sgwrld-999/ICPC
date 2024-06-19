#include <iostream>
#include <vector>
using namespace std;
/*
Problem name: Combination Sum
Problem link: https://leetcode.com/problems/combination-sum/
Explanation: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
We've to return the list of number which can be used to make the target sum.
Repeatation of the number is allowed.   
Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Let us understand the problem with the help of an example:
candidates = [2,3,6,7], target = 7
We have to find all the combinations of the numbers which can be used to make the target sum.
For index 0 i.e 2 we can either pick it or not pick it.
If we pick it then the target sum will be 7-2 = 5 and the array will be [2,3,6,7]
If we don't pick it then the target sum will be 7 and the array will be [2,3,6,7]
Similarly we can again pick 2 and the target sum will be 5 and the array will be [2,3,6,7]
If we don't pick it then the target sum will be 7 and the array will be [2,3,6,7]

So after pickiing up 3 times the targeted sum is 7-6 = 1 and the array will be [2,3,6,7]
If we pick 2 then the target sum will be 1-2 = -1 and the array will be [2,3,6,7] so we've to move ahead and check for the next element.
If we don't pick it then the target sum will be 1 and the array will be [2,3,6,7]
If we pick 3 then the target sum will be 1-3 = -2 and the array will be [2,3,6,7] so we've to move ahead and check for the next element.
If we don't pick it then the target sum will be 1 and the array will be [2,3,6,7]
If we pick 6 then the target sum will be 1-6 = -5 and the array will be [2,3,6,7] so we've to move ahead and check for the next element.
If we don't pick it then the target sum will be 1 and the array will be [2,3,6,7]
If we pick 7 then the target sum will be 1-7 = -6 and the array will be [2,3,6,7] so we've to move ahead and check for the next element.
If we don't pick it then the target sum will be 1 and the array will be [2,3,6,7]

Since no match is found we've to backtrack.

For case where 2 is picked 2 times we haven't picked again 2 so we'll move towards the index 1 i.e 3.
If we pick 3 then the target sum will be 7-4-3 = 4 and the array will be [2,3,6,7].

return the answer.

Similar approach towards the other elements as well.


*/
class Solution {
private:
    // Helper function to find all combinations that sum up to the target
    void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& results, vector<int>& currentCombination) {
        // Base case: if we've considered all elements
        if (index == candidates.size()) {
            // If the remaining target is 0, we found a valid combination
            if (target == 0) {
                results.push_back(currentCombination);
            }
            return;
        }

        // If the current candidate can be taken (it does not exceed the target)
        if (candidates[index] <= target) {
            // Include the current candidate in the combination
            currentCombination.push_back(candidates[index]);
            // Recur with the same index, since we can use the same element again
            findCombinations(index, target - candidates[index], candidates, results, currentCombination);
            // Backtrack: remove the last element added
            currentCombination.pop_back();
        }

        // Recur to the next candidate
        findCombinations(index + 1, target, candidates, results, currentCombination);
    }

public:
    // Function to find all unique combinations in candidates that sum up to target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> currentCombination;
        findCombinations(0, target, candidates, results, currentCombination);
        return results;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> results = sol.combinationSum(candidates, target);

    // Print the results
    for (const auto& combination : results) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
