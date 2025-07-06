

## 1. Brute-Force Solution

### Intuition

Try every pair `(i, j)` with `j > i`, keep track of the largest positive difference.

### Approach

1. Initialize `maxDiff = -1`.
2. Loop `i` from `0` to `n−2`.
3. For each `i`, loop `j` from `i+1` to `n−1`.
4. If `nums[j] > nums[i]`, compute `diff = nums[j] − nums[i]` and update `maxDiff`.
5. Return `maxDiff`.

### Complexity

* Time complexity:
  $O(n^2)$
* Space complexity:
  $O(1)$

### Code

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;            // edge-case guard

        int maxDiff = -1;
        // try every pair (i, j) with j > i
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    int diff = nums[j] - nums[i];
                    maxDiff = max(maxDiff, diff);
                }
            }
        }
        return maxDiff;
    }
};
```

---

## 2. Optimal (Single-Pass, Left-Min Tracking)

### Intuition

As you scan left→right, remember the smallest value seen so far (`minSoFar`). At each new element, see how big a gap you can make with that min.

### Approach

1. Guard small arrays (`n < 2`).
2. Set `minSoFar = nums[0]`, `maxDiff = -1`.
3. For each `i` from `1` to `n−1`:

   * If `nums[i] > minSoFar`, update `maxDiff = max(maxDiff, nums[i] − minSoFar)`.
   * Else update `minSoFar = nums[i]`.
4. Return `maxDiff`.

### Complexity

* Time complexity:
  $O(n)$
* Space complexity:
  $O(1)$

### Code

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1;            // edge-case guard

        int minSoFar = nums[0];
        int maxDiff = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > minSoFar) {
                maxDiff = max(maxDiff, nums[i] - minSoFar);
            } else {
                minSoFar = nums[i];
            }
        }
        return maxDiff;
    }
};
```

---

## 3. Most “Production-Ready” Version

### Intuition

Same one-pass idea, but with even clearer naming, early returns, and comments. 

### Approach

* **Validate input** immediately.
* Use **self-documenting names** (`smallestValue`, `largestGap`).
* Keep logic **flat**, each line does one thing.
* Document intent with brief comments.

### Complexity

* Time complexity:
  $O(n)$
* Space complexity:
  $O(1)$

### Code

```cpp
class Solution {
public:
    int maximumDifference(const vector<int>& nums) {
        int length = nums.size();
        if (length < 2) {
            // No possible pair -> defined as −1
            return -1;
        }

        int smallestValue = nums[0];
        int largestGap    = -1;

        for (int index = 1; index < length; ++index) {
            int current = nums[index];
            // If we can form a positive difference, consider it
            if (current > smallestValue) {
                int gap = current - smallestValue;
                largestGap = max(largestGap, gap);
            } else {
                // Update running minimum
                smallestValue = current;
            }
        }

        return largestGap;
    }
};
```

---

**How to Think About It**

1. **Brute force first**: ensure correctness by checking every possibility.
2. **Spot the pattern**: you only ever need the smallest “buy” before a “sell.”
3. **Optimize** by keeping that smallest in a variable—scan once.
4. **Refine for production**: use clear names, guard clauses, and comments.

