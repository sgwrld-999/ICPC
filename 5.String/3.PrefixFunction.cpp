#include<bits/stdc++.h>
using namespace std;
/*
Problem name: Prefix function
Problem link leetcode : https://leetcode.com/problems/longest-happy-prefix/
Explanation : https://cp-algorithms.com/string/prefix-function.html#prefix-function-definition
Approach 1 : Brute force
Let's dry run the given C++ code with a sample string `s = "abcabcd"` to understand how the nested loops work in calculating the prefix function using the brute force method.

### Input
```plaintext
s = "abcabcd"
```

### Initialization
- `n = 7` (length of the string)
- `pi = [0, 0, 0, 0, 0, 0, 0]` (initialize the prefix function array)

### Dry Run

#### Outer Loop (`i` from 0 to 6)

1. **`i = 0`**:
    - **Inner Loop (`len` from 0 to 0)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(0 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[0] = 0`
    - `pi = [0, 0, 0, 0, 0, 0, 0]`

2. **`i = 1`**:
    - **Inner Loop (`len` from 0 to 1)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(1 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[1] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(1 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(1, 1) = "b"`
            - They do not match.
    - `pi = [0, 0, 0, 0, 0, 0, 0]`

3. **`i = 2`**:
    - **Inner Loop (`len` from 0 to 2)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(2 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[2] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(2 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(2, 1) = "c"`
            - They do not match.
        - `len = 2`: Compare `s.substr(0, 2)` with `s.substr(2 - 2 + 1, 2)`:
            - `s.substr(0, 2) = "ab"`
            - `s.substr(1, 2) = "bc"`
            - They do not match.
    - `pi = [0, 0, 0, 0, 0, 0, 0]`

4. **`i = 3`**:
    - **Inner Loop (`len` from 0 to 3)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(3 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[3] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(3 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(3, 1) = "a"`
            - They match.
            - `pi[3] = 1`
        - `len = 2`: Compare `s.substr(0, 2)` with `s.substr(3 - 2 + 1, 2)`:
            - `s.substr(0, 2) = "ab"`
            - `s.substr(2, 2) = "ca"`
            - They do not match.
        - `len = 3`: Compare `s.substr(0, 3)` with `s.substr(3 - 3 + 1, 3)`:
            - `s.substr(0, 3) = "abc"`
            - `s.substr(1, 3) = "bca"`
            - They do not match.
    - `pi = [0, 0, 0, 1, 0, 0, 0]`

5. **`i = 4`**:
    - **Inner Loop (`len` from 0 to 4)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(4 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[4] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(4 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(4, 1) = "b"`
            - They do not match.
        - `len = 2`: Compare `s.substr(0, 2)` with `s.substr(4 - 2 + 1, 2)`:
            - `s.substr(0, 2) = "ab"`
            - `s.substr(3, 2) = "ab"`
            - They match.
            - `pi[4] = 2`
        - `len = 3`: Compare `s.substr(0, 3)` with `s.substr(4 - 3 + 1, 3)`:
            - `s.substr(0, 3) = "abc"`
            - `s.substr(2, 3) = "cab"`
            - They do not match.
        - `len = 4`: Compare `s.substr(0, 4)` with `s.substr(4 - 4 + 1, 4)`:
            - `s.substr(0, 4) = "abca"`
            - `s.substr(1, 4) = "bcab"`
            - They do not match.
    - `pi = [0, 0, 0, 1, 2, 0, 0]`

6. **`i = 5`**:
    - **Inner Loop (`len` from 0 to 5)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(5 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[5] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(5 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(5, 1) = "c"`
            - They do not match.
        - `len = 2`: Compare `s.substr(0, 2)` with `s.substr(5 - 2 + 1, 2)`:
            - `s.substr(0, 2) = "ab"`
            - `s.substr(4, 2) = "bc"`
            - They do not match.
        - `len = 3`: Compare `s.substr(0, 3)` with `s.substr(5 - 3 + 1, 3)`:
            - `s.substr(0, 3) = "abc"`
            - `s.substr(3, 3) = "abc"`
            - They match.
            - `pi[5] = 3`
        - `len = 4`: Compare `s.substr(0, 4)` with `s.substr(5 - 4 + 1, 4)`:
            - `s.substr(0, 4) = "abca"`
            - `s.substr(2, 4) = "cabc"`
            - They do not match.
        - `len = 5`: Compare `s.substr(0, 5)` with `s.substr(5 - 5 + 1, 5)`:
            - `s.substr(0, 5) = "abcab"`
            - `s.substr(1, 5) = "bcabc"`
            - They do not match.
    - `pi = [0, 0, 0, 1, 2, 3, 0]`

7. **`i = 6`**:
    - **Inner Loop (`len` from 0 to 6)**:
        - `len = 0`: Compare `s.substr(0, 0)` with `s.substr(6 - 0 + 1, 0)`: Both are empty strings, so they match.
        - `pi[6] = 0`
        - `len = 1`: Compare `s.substr(0, 1)` with `s.substr(6 - 1 + 1, 1)`:
            - `s.substr(0, 1) = "a"`
            - `s.substr(6, 1) = "d"`
            - They do not match.
        - `len = 2`:

Time complexity: O(n^3)
Space complexity: O(n)

*/
class Solution{
    public: 
    vector<int> bruteForce(string s){
        int n = s.size();
        vector<int> pi(n,0);
        for(int i = 0 ; i < n ; i++){
            for(int len = 0 ; len <= i ; len++){
                if(s.substr(0,len) == s.substr(i-len+1,len)){
                    pi[i] = len;
                }
            }
        }
        return pi;
    }
};

/*
Approach 2 : Optimized brute force
### Simplified Explanation with a Step-by-Step Approach

#### Concept:
The prefix function `pi[i]` for a string `s` at position `i` tells us the length of the longest proper prefix of the substring `s[0...i]` that is also a suffix of this substring.

#### Key Insight:
- The value of the prefix function can only increase by at most one as we move to the next character in the string.
- If `pi[i]` is the length of the longest proper prefix which is also a suffix at position `i`, then at position `i+1`, `pi[i+1]` can only be `pi[i]+1`, `pi[i]`, or less.

### Visual Explanation:
Imagine you are matching patterns in a string by sliding a window from the start of the string to the current position `i`.

#### Steps to Understand:
1. **Initialization**: Start with `pi[0] = 0` because a single character has no proper prefix.
2. **Loop through each character in the string** from the second character onwards (i.e., from index `1` to `n-1`):
    - Use the previous value `pi[i-1]` to determine the length of the longest prefix which might be extended.
    - Compare the current character with the character at the position just after the longest proper prefix.
    - If they match, extend the length of the prefix.
    - If they do not match, reduce the length of the prefix and try again until no match is found or the prefix length is reduced to zero.
3. **Update the prefix function array `pi`** with the new length of the longest proper prefix which is also a suffix.

### Dry Run with an Example
Let's use `s = "abcabcd"` and walk through the algorithm step by step:

1. **Initialization**: `pi = [0, 0, 0, 0, 0, 0, 0]`
2. **Index `1`**:
    - Compare `s[1]` (`b`) with `s[0]` (`a`), no match, so `pi[1] = 0`
    - `pi = [0, 0, 0, 0, 0, 0, 0]`
3. **Index `2`**:
    - Compare `s[2]` (`c`) with `s[0]` (`a`), no match, so `pi[2] = 0`
    - `pi = [0, 0, 0, 0, 0, 0, 0]`
4. **Index `3`**:
    - Compare `s[3]` (`a`) with `s[0]` (`a`), match, so `pi[3] = 1`
    - `pi = [0, 0, 0, 1, 0, 0, 0]`
5. **Index `4`**:
    - Compare `s[4]` (`b`) with `s[1]` (`b`), match, so `pi[4] = 2`
    - `pi = [0, 0, 0, 1, 2, 0, 0]`
6. **Index `5`**:
    - Compare `s[5]` (`c`) with `s[2]` (`c`), match, so `pi[5] = 3`
    - `pi = [0, 0, 0, 1, 2, 3, 0]`
7. **Index `6`**:
    - Compare `s[6]` (`d`) with `s[3]` (`a`), no match, backtrack using `pi` to compare `s[6]` with `s[0]`
    - No match found, so `pi[6] = 0`
    - `pi = [0, 0, 0, 1, 2, 3, 0]`

### Simplified Algorithm Code
Here's the code implementing the above logic:

### Summary
- **Key Insight**: The value of `pi[i+1]` can only be `pi[i]+1`, `pi[i]`, or less.
- **Algorithm Steps**:
  1. Initialize `pi[0] = 0`.
  2. Loop through each character, comparing with the prefix.
  3. Update the `pi` array based on matches.
- **Dry Run Example**: Walk through the steps with a specific string to see how the prefix function values are calculated.

### Flowchart Explanation:
1. **Start**.
2. **Initialize**: `pi[0] = 0`.
3. **Loop**: For each character from index `1` to `n-1`.
   - **Compare**: Check if the current character matches the next character in the prefix.
   - **Update**: Adjust the prefix length accordingly.
   - **Assign**: Set the current `pi` value.
4. **End**.
*/

class Solution2{
    public:
    vector<int> optimizedBruteForce(string s){
        int n = s.size();
        vector<int> pi(n,0);
        for(int i = 1 ; i < n ; i++){
            int len = pi[i-1];
            while(len > 0 && s[i] != s[len]){
                len = pi[len-1];
            }
            if(s[i] == s[len]){
                len++;
            }
            pi[i] = len;
        } 
        return pi;
    }
};


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    vector<int> prefix = Solution().bruteForce(s);
    for(auto x : prefix){
        cout<<x<<" ";
    }
    return 0;
}
