#include<iostream>
<vector>
using namespace std;

/*

### 🧠 Problem Understanding:

> You're given a string `s` consisting of digits from `'0'` to `'4'`, and an integer `k`.
> Your goal is to find the **maximum difference** between the frequencies of **two digits A and B** (where `A` must occur an **odd** number of times, and `B` an **even** number of times) inside **any substring** of `s` with length **at least `k`**.

---

### 💡 Step-by-Step Thought Process:

#### 1. **Brute Force Idea**:

> Generate all substrings of length ≥ `k`, and for each substring:
>
> * Try all valid digit pairs (A, B) where A ≠ B.
> * Count their frequencies.
> * If A's frequency is **odd** and B's is **even**, compute the difference.
> * Track the maximum such difference.

* **Drawback**: Too slow for large inputs. Time complexity is **O(n² × 25)**, not acceptable.

---

#### 2. **Key Observations for Optimization**:

* The digits are limited to only `'0'` to `'4'`, which means:

  * There are only **5 × 4 = 20 possible A-B pairs** (A ≠ B).
* For each valid A-B pair, we aim to find a substring where:

  * Frequency of A is odd.
  * Frequency of B is even.
  * The length is at least `k`.
* This reduces the problem to 20 independent subproblems, one for each (A, B) pair.

---

#### 3. **Using Sliding Window + Prefix Counting**:

> For each (A, B) pair:
>
> * Use prefix sums to track the frequency of A and B.
> * For each index `r`, maintain:
>
>   * Count of A till `r` (`countA[r]`)
>   * Count of B till `r` (`countB[r]`)
> * For any index `l` (with `r - l + 1 ≥ k`), the frequency of A in the window is `countA[r] - countA[l-1]`, and similar for B.

---

#### 4. **Tracking Valid Parity States with Bitmasking**:

* Each pair (A, B) at each index can have one of 4 parity combinations:

  * Even-Even, Even-Odd, Odd-Even, Odd-Odd → encoded as 2-bit masks.
* For each index, store a `state = (parity_of_A << 1) | parity_of_B`.
* We use a lookup table of size 4 to store the **minimum `countA - countB`** seen so far for each parity state.

---

#### 5. **Final Optimization Insight**:

> For a given state at index `r`, we can compute which previous state we need to subtract from to meet the A-odd & B-even condition:
>
> * This is achieved using `XOR 2` trick:

* Because XOR of current and previous state helps us isolate the difference in parity.

> With this, at every index:
>
> * We know the best possible previous state (from lookup).
> * We compute the score = (current countA - countB) − (lookup of previous best).
> * Update result if this score is higher and substring length ≥ `k`.

---

### ✅ Final Approach:

1. Loop through all 20 valid `(A, B)` digit pairs.
2. For each pair:

   * Use prefix counting and sliding window to compute frequencies.
   * Track parity states and their best `countA - countB`.
   * Use XOR + hashmap to track optimal difference.
3. Return the maximum score across all pairs and valid substrings.

---

### 🔚 Conclusion:

> This is an **expert-level sliding window + prefix sum + bitmask optimization problem**, where constraints and problem structure guide us to prune brute force and apply clever counting logic.
> The key challenge was **parity tracking** and ensuring we remove characters in a way that maintains **odd/even frequency conditions**.

---
*/
