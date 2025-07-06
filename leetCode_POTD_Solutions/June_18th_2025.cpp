#include<iostream>
#include<vector>

using namespace std;


/*
### ✅ **How I Would Explain My Thought Process in the Interview**

---

### 🧠 **Understanding the Problem**

> "The problem asks us to divide the given array into groups of exactly 3 elements such that the **maximum difference** between any two elements in a group is at most `k`.
> If it's not possible, we return an empty vector."

---

### 💡 **Initial Intuition**

> "The most important observation here is that if the elements are **sorted**, then any group of 3 **consecutive elements** that have a difference `≤ k` between the smallest and largest is guaranteed to be valid.

> So instead of checking all combinations, I thought: *Why not sort the array and process it in chunks of 3?* This guarantees both correctness and efficiency."

---

### 🧩 **Step-by-Step Approach**

1. **Sort the Array**

   > "I first sorted the array to bring elements of similar value together. This increases the chance of forming valid triplets and makes difference checking straightforward."

2. **Check in Groups of 3**

   > "Then I iterate in steps of 3 (since each group must be exactly 3). For every group, I only need to check if the difference between the first and third elements is greater than `k` — that covers all pairwise differences in the group."

3. **Early Exit**

   > "If any such group violates the rule, I return an empty result immediately since no valid grouping is possible."

---

### 🔒 **Edge Case Considerations**

> "In real-world code, I’d make sure to check:

* Whether the array length is divisible by 3 — if not, grouping into triplets isn’t even possible.
* Also, protect against index out-of-bounds by ensuring `i + 2 < n` during iteration."

---

### 🛠️ **Why This Approach Works**

> "Sorting helps reduce the complexity of decision-making — it guarantees that groups of 3 consecutive elements are always the closest possible in value.
> This gives us a reliable and efficient way to solve the problem in linear time after sorting."

---

### 🧮 **Time and Space Complexity**

* **Time Complexity**:

  > `O(n log n)` due to sorting + `O(n)` for grouping ⇒ Total: `O(n log n)`
* **Space Complexity**:

  > `O(n)` for storing the result; in-place sort if allowed

---

### ✅ **Conclusion**

> "So in summary:

* Sort the array
* Process in chunks of 3
* Check difference constraint
* Return the result if all groups are valid, otherwise return empty

This approach is clean, optimal, and scalable."

*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Check if array size is divisible by 3
        if (n % 3 != 0) return {};

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            // Prevent index out-of-bounds and check validity
            if (i + 2 >= n || (nums[i + 2] - nums[i] > k)) {
                return {};
            }
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return result;
    }
};


