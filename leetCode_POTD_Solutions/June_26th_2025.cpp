
# Brute-Force Recursive Exploration

# Intuition

We want the longest subsequence of the binary string `s` that, when interpreted as a binary number, is ≤ k.
A natural first thought is: at each position, decide **take** or **skip** the current bit and recursively solve the remainder, keeping track of the remaining “budget” (k minus the value you’ve taken so far).

# Approach

1. **Define** a recursive function `solve(s, k, i)` that returns the maximum subsequence length using only indices `0…i`, with budget `k`.
2. **Base case**: if `i < 0`, no characters left → return 0.
3. **Choice** at `i`:

   * Compute the value of including `s[i]` (if it’s ‘1’, its binary weight is `1 << (n-i-1)`).
   * If that value ≤ k, **take** it: `1 + solve(s, k–value, i–1)`.
   * Always consider **skip**: `solve(s, k, i–1)`.
4. **Return** the max of **take** and **skip**.

# Complexity

* Time complexity: $O(2^n)$ (each index branches into two calls)
* Space complexity: $O(n)$ (recursion depth)

# Code

```cpp
// Brute force: exponential time
class Solution {
public:
    int n;

    // Recursively compute longest valid subsequence in s[0..i] with budget k
    int solve(const string &s, long long k, int i) {
        if (i < 0) 
            return 0;

        // Value of including s[i]
        int bit = s[i] - '0';
        long long value = bit 
            ? (1LL << (n - i - 1))  // weight of this bit
            : 0;

        int take = 0;
        if (value <= k) {
            take = 1 + solve(s, k - value, i - 1);
        }
        int skip = solve(s, k, i - 1);
        return max(take, skip);
    }

    int longestSubsequence(string &s, int k) {
        n = s.length();
        return solve(s, k, n - 1);
    }
};
```

---

# Optimized Greedy from Least Significant Bit

# Intuition

We can build the subsequence by scanning from the **right** (least significant bit) toward the left.

* Every ‘0’ can always be taken (it adds nothing to the numeric value).
* A ‘1’ can only be taken if its current binary weight ≤ k; once we take it, we deduct that weight from k.
* As we move left, the next ‘1’ doubles in weight—so we track and update the running power of two.

# Approach

1. Initialize `len = 0` (length of chosen subsequence) and `power = 1` (weight of the current bit, starting at the least significant).
2. **Iterate** `i` from `n–1` down to `0`:

   * If `s[i] == '0'`, always `len++`.
   * Else (bit = ‘1’) **and** `power ≤ k`: take it → `len++, k -= power`.
   * **Before** moving to the next more-significant bit, update `power = min(power × 2, k+1)` to avoid overflow (or simply `power <<= 1` but guard if you like).
3. **Return** `len`.

# Complexity

* Time complexity: $O(n)$ (single pass)
* Space complexity: $O(1)$ (constant extra space)

# Code

```cpp
// Optimized: linear time
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int len = 0;
        long long power = 1;  // weight of the least significant bit

        // Scan from LSB (rightmost) to MSB (leftmost)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // '0' contributes no numeric value — always safe to take
                len++;
            }
            else if (power <= k) {
                // If we can afford this '1', take it
                len++;
                k -= power;
            }
            // Move to next bit weight (double)
            power <<= 1;
        }

        return len;
    }
};
```

