/*
Thought process:

- We start with the string "a".
- In every step, we append the successor of each character in the string:
  "a" -> "ab", because successor of 'a' is 'b'
  "ab" -> "abbc", because successors are 'b' and 'c'
  So the string becomes: a -> ab -> abbc -> abbcbccd -> ...
- We continue this process until the string length becomes ≥ k.
- Then we simply return the (k-1)th character.

Fixes:
- `s[i]` was incorrect; it should be `word[i]`.
- Efficient handling of successor: if 'z', then wrap to 'a', else add 1 to the character.
*/

class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while (k > word.size()) {
            string temp = "";

            for (int i = 0; i < word.size(); i++) {
                if (word[i] == 'z') {
                    temp += 'a';
                } else {
                    temp += word[i] + 1;
                }
            }

            word += temp;
        }

        return word[k - 1]; // 1-based indexing
    }
};

