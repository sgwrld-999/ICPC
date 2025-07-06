### # Intuition

To divide a string into fixed-size chunks, we can simply iterate through the string in steps of size `k`. If the remaining characters at the end are fewer than `k`, we pad them with a `fill` character. This makes the logic straightforward and avoids complicated index handling.

---

### # Approach

* Initialize a result vector to store the chunks.
* Loop through the string in increments of `k`.
* For each step:

  * Construct a chunk by adding up to `k` characters.
  * If the chunk has fewer than `k` characters left from the original string, fill the rest with the `fill` character.
* Append each chunk to the result vector.
* Return the result.

---

### # Complexity

* **Time complexity:**
  $O(n)$
  We iterate through each character in the string exactly once.

* **Space complexity:**
  $O(n)$
  We store the entire output as a vector of strings, which takes proportional space to the input size.

---

### # Code

```cpp
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();

        for (int i = 0; i < n; i += k) {
            string chunk = "";
            for (int j = 0; j < k; ++j) {
                if (i + j < n)
                    chunk += s[i + j];
                else
                    chunk += fill;
            }

            result.push_back(chunk);
        }

        return result;
    }
};
```

