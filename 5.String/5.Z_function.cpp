#include<bits/stdc++.h>
using namespace std;

/*
Z - Function for a string S is defined as an array of length n (assuming string length is n),
where the i-th element is equal to the greatest number of elements starting from index i that 
coincide with the first characters of S.

Example : 
a b a b b 
 -> Z-Function array for the string "ababb"

Why Z[2] = 2 
Approach1: 
To provide a clear understanding of how the `zFunction` method in the `Z_function` class works, let's create a flowchart for a specific example. We will use the string "abacaba" to illustrate the steps taken by the function.

### Flowchart Description

1. Start: Begin the process.
2. Input String: "abacaba".
3. Initialize Variables:
   - `n` = length of the string = 7.
   - `z` = array of zeros with size `n` = [0, 0, 0, 0, 0, 0, 0].
4. Outer Loop (i from 0 to n-1):
   - Inner Loop (j from i to n-1):
     - **Check** if `s[j]` equals `s[j-i]`:
       - If **true**, increment `z[i]`.
       - If **false**, break the inner loop.
5. **End of Loops**: All iterations are complete.
6. **Output**: The final `z` array.
7. **Stop**: End the process.

### Example Execution: "abacaba"

- **i = 0**:
  - j = 0: s[0] == s[0] (a == a), z[0]++
  - j = 1: s[1] == s[1-0] (b == b), z[0]++
  - j = 2: s[2] == s[2-0] (a == a), z[0]++
  - j = 3: s[3] == s[3-0] (c == c), z[0]++
  - j = 4: s[4] == s[4-0] (a == a), z[0]++
  - j = 5: s[5] == s[5-0] (b == b), z[0]++
  - j = 6: s[6] == s[6-0] (a == a), z[0]++
- **i = 1**:
  - j = 1: s[1] == s[1-1] (b == a), break
- **i = 2**:
  - j = 2: s[2] == s[2-2] (a == a), z[2]++
  - j = 3: s[3] == s[3-2] (c == b), break
- **i = 3**:
  - j = 3: s[3] == s[3-3] (c == a), break
- **i = 4**:
  - j = 4: s[4] == s[4-4] (a == a), z[4]++
  - j = 5: s[5] == s[5-4] (b == b), z[4]++
  - j = 6: s[6] == s[6-4] (a == a), z[4]++
- **i = 5**:
  - j = 5: s[5] == s[5-5] (b == a), break
- **i = 6**:
  - j = 6: s[6] == s[6-6] (a == a), z[6]++

### Final `z` Array:
- z = [7, 0, 1, 0, 3, 0, 1]

This flowchart and example execution provide a step-by-step visualization of how the `zFunction` computes the Z-values for the string "abacaba". Each step in the loops checks characters and updates the Z-array accordingly.
*/

class Z_function{
public:
    void zFunction(string s){
        int n = s.size();
        vector<int> z(n, 0);
        for(int  i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(s[j] == s[j-i]){
                    z[i]++;
                }
                else{
                    break;
                }
            }
        }
    }
};
/*
Segment match:
A substring which matches with prefix of the string is called segement match.
Example: 
a b c a d a b c

Segment1 : a, length = 1 , L = 3 , R = 3
Segment2 : a b c, length = 3 , L = 5 , R = 7

Rightmost segment match:
A segment match which ends at the rightmost position of the string is called rightmost segment match.
Example:
a a c a d a b c
Segment2 : a, length = 1 , L = 1 , R = 1
Segment1 : a, length = 1 , L = 3 , R = 3
Segment3 : a b c, length = 3 , L = 5 , R = 7

*/

vector<int> z_Function(string s){
    int n = (int)s.length(); 
    vector<int> z(n, 0);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        // Rightmost segment match
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        // Segment match
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
