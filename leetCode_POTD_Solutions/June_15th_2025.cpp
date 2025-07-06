i# 🔍 Problem Statement

You're given a positive integer `num`. You can **replace all digits** of **one chosen digit** with **another digit (0-9)**, **only once**. You must **maximize** and **minimize** the result of this operation and return the **difference** between the two results.

---

# 🧠 Intuition

We are allowed to do one type of digit replacement — change all instances of one digit to another.
So the idea is simple:

* To **maximize** the number, we want to convert smaller digits to larger ones (ideally to `9`).
* To **minimize** the number, we want to convert larger digits to smaller ones (ideally to `1` or `0`, avoiding leading zero).

---

# 🔨 Brute Force Approach

### How to Think

Try all combinations of digits `d1 -> d2` (replace digit `d1` with digit `d2`, for all 0–9). For each result:

* Keep track of the **maximum** and **minimum** numbers obtained.
* Return the **difference**.

---

# Approach

1. Loop over all digits `fromDigit` in `0–9`.
2. For each `fromDigit`, loop over all `toDigit` in `0–9`.
3. Replace all instances of `fromDigit` with `toDigit`.
4. If valid (no leading 0), update max and min.
5. Return the difference.

---

# Complexity

* Time complexity: $O(100 \cdot n) = O(n)$
  (We do 100 replacements; `n` is digit length.)
* Space complexity: $O(n)$
  (We use extra strings to hold transformed numbers.)

---

# ✅ Optimal Approach (Current Code)

### How to Think

Rather than checking all digit replacements, we look at:

* **First non-9 digit** for maximizing — change it and all occurrences to `9`.
* **First suitable digit** for minimizing — change it and all occurrences to `1` or `0`.

This avoids unnecessary iterations and gives us the best and worst values directly.

---

# Approach

* To get **max**:

  * Replace all occurrences of the **first digit ≠ '9'** with `'9'`.
* To get **min**:

  * If the **first digit ≠ '1'**, change all its occurrences to `'1'`.
  * Else, look for the **first non-zero, non-one digit** after index 0 and change all its occurrences to `'0'`.
* Convert both modified strings to numbers and return their difference.

---

# Complexity

* Time complexity: $O(n)$
  (One pass for max and one for min.)
* Space complexity: $O(n)$
  (To store copies of the string.)

---

# ✅ Most Optimized (Clean, Readable, Follows Software Engineering Principles)

* Modularize logic into clear helper functions if necessary.
* Use meaningful variable names.
* Maintain readability and avoid repeated logic.

---

# Code

```cpp
class Solution {
public:
    int maxDiff(int num) {
        string original = to_string(num);

        // Build max number
        string maxStr = original;
        char digitToReplaceMax = '\0';
        for (char digit : original) {
            if (digit != '9') {
                digitToReplaceMax = digit;
                break;
            }
        }
        if (digitToReplaceMax != '\0') {
            for (char &digit : maxStr) {
                if (digit == digitToReplaceMax) {
                    digit = '9';
                }
            }
        }

        // Build min number
        string minStr = original;
        char digitToReplaceMin = '\0';
        if (original[0] != '1') {
            digitToReplaceMin = original[0];
            for (char &digit : minStr) {
                if (digit == digitToReplaceMin) {
                    digit = '1';
                }
            }
        } else {
            for (int i = 1; i < original.size(); ++i) {
                if (original[i] != '0' && original[i] != '1') {
                    digitToReplaceMin = original[i];
                    break;
                }
            }
            if (digitToReplaceMin != '\0') {
                for (char &digit : minStr) {
                    if (digit == digitToReplaceMin) {
                        digit = '0';
                    }
                }
            }
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};
```

---

# ✅ Summary

| Version        | Time Complexity | Space Complexity | Notes                             |
| -------------- | --------------- | ---------------- | --------------------------------- |
| Brute Force    | O(n)            | O(n)             | Try all digit pairs               |
| Optimal        | O(n)            | O(n)             | Smart digit selection             |
| Most Optimized | O(n)            | O(n)             | Clean, readable, production-ready |

