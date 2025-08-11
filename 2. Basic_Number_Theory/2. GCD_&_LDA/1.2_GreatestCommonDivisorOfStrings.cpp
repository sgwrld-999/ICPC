#include<iostream>
#include<string>
using namespace std;

/**
 * Thought Process:
 * - A string divides another if the second string is made by repeating the first multiple times.
 * - If a GCD string exists, str1 + str2 must equal str2 + str1 (same repeating pattern).
 * - The length of the GCD string will be the GCD of lengths of str1 and str2.
 * - Steps:
 *    1. Check if str1 + str2 == str2 + str1. If not, return "".
 *    2. Find gcdLen = gcd(len(str1), len(str2)).
 *    3. Return the first gcdLen characters of str1 as the answer.
 */

 /*

## **1. What does "GCD of strings" mean?**

For numbers, GCD is the **largest number** that divides both without remainder.

For strings, **"divides"** means:

* A string `t` divides `s` if `s` is made by repeating `t` multiple times.

Example:

* `"ABC"` divides `"ABCABC"` because `"ABC" + "ABC" = ABCABC"`.
* `"AB"` divides `"ABABAB"` because `"AB" + "AB" + "AB" = ABABAB"`.

---

## **2. What would the GCD of two strings look like?**

Take two examples:

### Example 1

`str1 = "ABCABC"`, `str2 = "ABC"`

* `"ABC"` divides both → so `"ABC"` is the **GCD string**.

---

### Example 2

`str1 = "ABABAB"`, `str2 = "ABAB"`

* Both are made by repeating `"AB"`:
  `"ABABAB" = "AB" * 3`
  `"ABAB"   = "AB" * 2`
* So `"AB"` is the **GCD string**.

---

### Counterexample

`str1 = "ABC"`, `str2 = "AB"`

* `"ABC" + "AB" = "ABCAB"`
* `"AB" + "ABC" = "ABABC"`
* Not equal → no common repeating unit → GCD string is `""`.

---

## **3. Why does `str1 + str2 == str2 + str1` work?**

If two strings share a repeating unit, then **no matter the order you concatenate them, the result is the same**.

Example with `"ABCABC"` and `"ABC"`:

* `"ABCABC" + "ABC" = "ABCABCABC"`
* `"ABC" + "ABCABC" = "ABCABCABC"`
  ✅ Equal → same repeating pattern exists.

Counterexample with `"ABC"` and `"AB"`:

* `"ABC" + "AB" = "ABCAB"`
* `"AB" + "ABC" = "ABABC"`
  ❌ Not equal → no common repeating pattern.

So, **this check quickly filters out cases with no GCD string**.

---

## **4. How does length GCD fit in?**

If a common divisor string exists:

* Its length must divide both `len(str1)` and `len(str2)` evenly.
* The biggest possible divisor length = `gcd(len(str1), len(str2))`.

Example:
`str1 = "ABCABC" (len=6)`
`str2 = "ABC" (len=3)`
`gcd(6, 3) = 3` → so the GCD string must have length 3.
The first 3 characters of str1 = `"ABC"` → that’s the GCD string.

---

## **5. How the algorithm flows**

1. Check `str1 + str2 == str2 + str1`. If not equal → return `""`.
2. If equal → Find `gcd(len(str1), len(str2))`.
3. Return the **prefix of str1** of that length.

---

## **6. Visual Summary**

```
str1 = "ABCABC"
str2 = "ABC"

str1 + str2 = "ABCABCABC"
str2 + str1 = "ABCABCABC"  ✅ equal

len1 = 6, len2 = 3
gcd(6, 3) = 3
Prefix of length 3 from str1 = "ABC"
```

 */
/*
Gotcha — you’re basically saying:
*"I get that this is like GCD for numbers, where we care about lengths, remainders, and divisibility — but how exactly does that play out for strings?"*

Let’s walk through that **Euclidean algorithm for strings** intuition step-by-step.

---

## **1. GCD for numbers refresher**

For numbers:

```text
gcd(6, 3) = 3
gcd(8, 3) → gcd(3, 8 % 3) → gcd(3, 2) → gcd(2, 1) → gcd(1, 0) = 1
```

We reduce the problem by replacing `(a, b)` with `(b, a % b)` until remainder = 0.

---

## **2. How to translate this to strings**

We can think of **string remainder** like this:

* If `str1` starts with `str2`, then `str1` can be **shortened** by removing that prefix.
* That’s equivalent to `a % b` in numbers — we remove one multiple of `b` from `a`.
* Then we **repeat the process** until one string becomes empty.

---

## **3. Step-by-step example**

Example:
`str1 = "ABCABC"`, `str2 = "ABC"`

```
Step 1:
- str1 starts with str2 → remove "ABC" from start of str1
- str1 becomes "ABC"
- Now gcd("ABC", "ABC") → both equal → return "ABC"

```

It matches number GCD:

```
len1 = 6, len2 = 3
gcd(6, 3) → gcd(3, 0) = 3
```

---

### Example 2 (with remainder)

`str1 = "ABABAB"`, `str2 = "ABAB"`

```
Step 1:
- str1 starts with str2 ("ABAB")
- Remove "ABAB" from str1 → str1 = "AB"
- Now gcd("ABAB", "AB") → swap so larger string is first

Step 2:
- "ABAB" starts with "AB"
- Remove "AB" → "AB"
- gcd("AB", "AB") → return "AB"
```

Matches number GCD:

```
len1 = 6, len2 = 4
gcd(6, 4) → gcd(4, 2) → gcd(2, 0) = 2 → substring length = 2 → "AB"
```

---

## **4. Why this works**

* In numbers, `a % b` removes the largest chunk of `b` from `a`.

* In strings, **removing `str2` from the start of `str1`** is doing the exact same thing —
  it’s removing one multiple of `str2` from `str1`.

* Just like with numbers, if at some point `str1` doesn’t start with `str2`,
  it means there’s **no common divisor** → return `""`.

---

## **5. Recursive Implementation**

This is the *pure Euclidean string GCD* form:

```cpp
string gcdOfStrings(string str1, string str2) {
    if (str1 == str2) return str1;
    if (str1.size() > str2.size()) {
        if (str1.rfind(str2, 0) == 0) // str1 starts with str2
            return gcdOfStrings(str1.substr(str2.size()), str2);
        else
            return "";
    } else {
        if (str2.rfind(str1, 0) == 0) // str2 starts with str1
            return gcdOfStrings(str1, str2.substr(str1.size()));
        else
            return "";
    }
}
```


*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 == str2) return str1;
        if (str1.size() > str2.size()) {
            if (str1.rfind(str2, 0) == 0) // str1 starts with str2
                return gcdOfStrings(str1.substr(str2.size()), str2);
            else
                return "";
        } else {
            if (str2.rfind(str1, 0) == 0) // str2 starts with str1
                return gcdOfStrings(str1, str2.substr(str1.size()));
            else
                return "";
        }
    }
//     string gcdOfStrings(string str1, string str2) {
//         // Step 1: Check for same pattern
//         if (str1 + str2 != str2 + str1)
//             return "";

//         // Step 2: Find GCD of lengths
//         int gcdLen = gcd((int)str1.size(), (int)str2.size());

//         // Step 3: Return substring of length gcdLen
//         return str1.substr(0, gcdLen);
//     }
};

/*
Python code:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        gcdLen = self.gcd(len(str1), len(str2))
        return str1[:gcdLen]
 */