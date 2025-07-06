
# Intuition

We are given a string and need to ensure that the **maximum frequency difference** between any two characters is at most `k`.
To achieve this, we are allowed to delete characters.
So, we want to minimize the number of deletions such that all character frequencies are within a difference of `k`.

---

# Approach

### ✅ **Approach 1: Brute-force over frequencies**

1. Count the frequency of each character.
2. For each character frequency `freq[i]`, try to make all other character frequencies within `k` of `freq[i]`.
3. If a character's frequency is too high, delete the excess.
4. If it's already less than or equal to `freq[i]`, we may delete it entirely.
5. Track the minimum deletions across all choices.

This approach tries all 26 possible frequencies to keep and adjusts others around them.

---

### ✅ **Approach 2: Optimized by Sorting Frequencies**

1. Count frequency of each character (26 lowercase letters).
2. Sort the frequency array in ascending order.
3. Try every character frequency as a **potential minimum**.
4. For each such frequency `minFreq = freq[i]`:

   * Delete all characters before it (`deletedSoFar`).
   * For all higher frequencies, if `freq[j] - minFreq > k`, delete the extra part.
5. Track and update the minimum deletions across all valid `minFreq` choices.

This approach avoids redundant checks by using sorting and early break conditions to reduce unnecessary computation.

---

# Complexity

### Approach 1:

* **Time complexity:** `O(26 × 26)` = `O(1)` (constant for lowercase letters)
* **Space complexity:** `O(1)` (fixed-size frequency array)

### Approach 2:

* **Time complexity:** `O(n + 26 log 26)` → `O(n)` for counting + sorting 26 elements
* **Space complexity:** `O(1)` (only 26-element frequency array)

---

# Code

```cpp []
// Approach 2: Optimized Using Sorted Frequencies
class Solution {
public:
    int minimumDeletions(string word, int k) {
        const int ALPHABET_SIZE = 26;
        const char BASE_CHAR = 'a';

        // Frequency count of each character
        vector<int> freq(ALPHABET_SIZE, 0);
        for (char ch : word) {
            freq[ch - BASE_CHAR]++;
        }

        // Sort the frequencies in ascending order
        sort(begin(freq), end(freq));

        int result = INT_MAX;
        int deletedSoFar = 0;

        // Try each unique frequency as the minimum allowed
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            int minFreq = freq[i];
            int deletionsNeeded = deletedSoFar;

            // For characters with frequency higher than minFreq + k,
            // delete the excess characters
            for (int j = ALPHABET_SIZE - 1; j > i; --j) {
                if (freq[j] - minFreq <= k) break;
                deletionsNeeded += freq[j] - (minFreq + k);
            }

            result = min(result, deletionsNeeded);
            deletedSoFar += minFreq;
        }

        return result;
    }
};
```

---

### ✅ Alternative: Brute-Force Frequency Matching

```cpp
// Approach 1: Try All Frequencies as Base
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for(char &ch : word) {
            freq[ch - 'a']++;
        }

        int result = word.length();

        for(int i = 0; i < 26; i++) {
            int deletions = 0;

            for(int j = 0; j < 26; j++) {
                if(i == j) continue;

                if(freq[j] < freq[i]) {
                    deletions += freq[j];
                } else if(abs(freq[j] - freq[i]) > k) {
                    deletions += abs(freq[j] - freq[i] - k);
                }
            }

            result = min(result, deletions);
        }

        return result;
    }
};
```

