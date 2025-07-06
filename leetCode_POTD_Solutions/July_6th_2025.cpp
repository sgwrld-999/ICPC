# Intuition
<!--
To find a lucky integer, I need to count the frequency of each number. A number is lucky if its value equals its frequency.
The twist is: I must return the *largest* such number if there are multiple. So I need to scan the frequencies and track the max lucky number.
-->

# Approach
<!--
1. Traverse the array and count the frequency of each number using an unordered_map.
2. Then traverse the map and check for numbers whose value == frequency.
3. Among such numbers, keep track of the maximum lucky number.
4. If none found, return -1.
-->

# Complexity
- Time complexity: $$O(n)$$
  - One pass for frequency count, one pass over the map.
- Space complexity: $$O(n)$$
  - For the frequency map.

# Code
cpp []
```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        int maxLucky = -1;

        // Step 2: Check for lucky numbers
        for (auto& [num, count] : freq) {
            if (num == count) {
                maxLucky = max(maxLucky, num);
            }
        }

        return maxLucky;
    }
};

