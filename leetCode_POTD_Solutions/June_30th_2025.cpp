# Intuition

<!-- Describe your first thoughts on how to solve this problem. -->  

At first glance, this problem seems similar to a frequency-based problem. The term **“longest harmonious subsequence”** means we need to find a subsequence where the **maximum and minimum values differ exactly by 1**.
This hints that for every number `x`, if `x+1` exists, the count of both `x` and `x+1` should be added, and we track the maximum of all such pairs.

# Approach

<!-- Describe your approach to solving the problem. -->  

* Use a **hash map** to count the frequency of each number in the array.
* Iterate over the keys of the map. For each key `num`, check if `num + 1` exists in the map.
* If it exists, it means we have a harmonious subsequence formed by `num` and `num + 1`, and its length would be the sum of their frequencies.
* Track the maximum length across all such valid pairs.
* Finally, return the length of the longest harmonious subsequence found.

# Complexity

* Time complexity:
  $O(n)$
  Where `n` is the size of the input array. We traverse the array once to build the frequency map and once more to find valid pairs.

* Space complexity:
  $O(n)$
  For storing the frequency of each number in the hash map.

---

# Code

```cpp
/*
Thought process:
- Initially, I thought of finding the min and max elements and calculating frequency, but that wouldn’t cover internal values.
- After re-reading the problem carefully, I realized the goal is to find the longest subsequence where two values differ by exactly 1.
- That gave me the idea to use a hash map to store the frequency of each number.
- If for any number `num`, `num + 1` exists in the map, then `freq[num] + freq[num+1]` is a valid candidate for LHS.
- Iterate all keys and track the maximum of such valid subsequences.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        int maxLength = 0;

        // For each unique number, check if number + 1 exists
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                maxLength = max(maxLength, count + freq[num + 1]);
            }
        }

        return maxLength;
    }
};
```
