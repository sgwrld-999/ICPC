
# Brute-Force Solution

---

# Intuition

<!-- Describe your first thoughts on how to solve this problem. -->

Before optimizing, my first thought was to **check for each element** what other elements it can group with, such that the **difference between the max and min in the group is ≤ `k`**.

Since I don't have any structure yet (like a sorted array), I thought of using a `visited` array to keep track of which elements are already placed into some group, and then iterating through all elements to find compatible ones for grouping.

---

# Approach

<!-- Describe your approach to solving the problem. -->

1. Create a `visited` array of size `n`, initialized to `false`, to track which elements have already been placed into a group.
2. Iterate through the array:

   * For each unvisited element, treat it as the start of a new group.
   * Compare it with every other unvisited element.
   * If the absolute difference between the current element and the new one is ≤ `k`, include that element in the group and mark it as visited.
3. Every time we initiate a new group, increment the `partitionCount`.

This solution works but is inefficient due to redundant comparisons.

---

# Complexity

* **Time complexity:**
  $O(n^2)$
  For each element, we may end up comparing it with every other unvisited element.

* **Space complexity:**
  $O(n)$
  We use a `visited` array of size `n`.

---

# Thinking Process / How to Explain in an Interview

In an interview, I would say:

> "To get a working solution quickly, I started with a brute-force approach. I wanted to group elements where the maximum difference in the group is ≤ `k`. I used a `visited` array to ensure elements aren't reused across groups. For each unvisited element, I tried to include as many compatible elements as possible.
>
> This approach is intuitive and useful for verifying correctness, but clearly inefficient for large inputs. Once I had this working, I started thinking about how to eliminate redundant work—leading me to consider sorting and a greedy strategy."

---

# Code

```cpp
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int partitionCount = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;

            visited[i] = true;
            int groupMin = nums[i];
            int groupMax = nums[i];

            for (int j = 0; j < n; ++j) {
                if (!visited[j]) {
                    int potentialMin = min(groupMin, nums[j]);
                    int potentialMax = max(groupMax, nums[j]);

                    if (potentialMax - potentialMin <= k) {
                        visited[j] = true;
                        groupMin = potentialMin;
                        groupMax = potentialMax;
                    }
                }
            }

            partitionCount++;
        }

        return partitionCount;
    }
};
```
---
# Optimal Solution
---

# Intuition

<!-- Describe your first thoughts on how to solve this problem. -->

The goal is to partition the array into the **minimum number of groups** such that the **maximum difference** within each group is at most `k`.

My initial thought was:

* If we **sort the array**, then we can group elements in a greedy way.
* As long as the difference between the current element and the first element of the group is ≤ `k`, it can stay in the group.
* Otherwise, we start a new group.

This ensures each group respects the constraint, and we minimize the total number of groups.

---

# Approach

<!-- Describe your approach to solving the problem. -->

1. **Sort the array** to bring elements into a predictable order.
2. Initialize a `count` variable to 1, since we will always have at least one group.
3. Use a variable `minVal` to track the first (smallest) number in the current group.
4. Iterate through the array:

   * If the current number `nums[i]` is more than `k` away from `minVal`, we can’t include it in the current group.
   * So, we increment `count` and start a new group with `minVal = nums[i]`.
5. Return the total `count` of such groups at the end.

This greedy approach is both intuitive and efficient, especially after sorting.

---

# Complexity

* **Time complexity:**
  $O(n \log n)$
  Sorting the array takes `O(n log n)`, and the grouping logic is `O(n)`.

* **Space complexity:**
  $O(1)$
  We use only constant extra space for counters and tracking variables.

---

# Thinking Process / How to Explain in an Interview

In an interview, I would say:

> "I started by understanding the core requirement — we need to partition the array into groups where the maximum difference is ≤ `k`. That’s a strong hint that **ordering matters**, so my first step is to sort the array.
>
> Once sorted, we can scan from left to right and group as many adjacent elements as possible until the difference exceeds `k`. At that point, I start a new group.
>
> This greedy approach is effective here because once an element violates the `k` constraint, there’s no way it can belong to the same group as the earlier elements—thanks to the sorted order. This makes the algorithm both correct and optimal."

---

# Code

```cpp
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));  // Step 1: Sort the array

        int count = 1;                 // At least one group
        int minVal = nums[0];          // Start of the first group

        for (int i = 0; i < n; i++) {
            // If current number can't be in the current group
            if (nums[i] - minVal > k) {
                count++;               // Start new group
                minVal = nums[i];     // Reset minVal for new group
            }
        }

        return count;
    }
};



