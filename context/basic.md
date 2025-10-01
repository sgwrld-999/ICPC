# Complete DSA Patterns & Algorithms Reference Guide

> **Expert-Level Knowledge Base for Competitive Programming & Interviews**
> 
> *Based on 15+ years of hands-on experience in Data Structures, Algorithms & Competitive Programming*

---

## **Table of Contents**

1. [Sliding Window Technique](#sliding-window-technique)
2. [Linear Search & Array Operations](#linear-search--array-operations)
3. [Circular Array & Queue Operations](#circular-array--queue-operations)
4. [Number Theory Problems](#number-theory-problems)
5. [Quick Reference Tables](#quick-reference-tables)

---

## **Sliding Window Technique**

### **1. Core Concept & Definition**

**What it is:** A technique to efficiently process subarrays/substrings by maintaining a "window" that slides across the data structure.

**Fundamental Properties:**
- **Two Pointers:** `left` and `right` define window boundaries
- **Dynamic Size:** Window expands/contracts based on conditions
- **Optimal Traversal:** Each element visited at most twice (once by right, once by left)
- **State Maintenance:** Track window properties (sum, frequency, etc.)

**Memory Representation:**
```
Array: [a, b, c, d, e, f]
        ↑     ↑
      left  right
Window: [b, c, d] (size = right - left + 1)
```

### **2. When to Use (Pattern Recognition Triggers)**

**Immediate Keywords:**
- "subarray", "substring", "contiguous elements"
- "window of size k", "longest/shortest", "maximum/minimum"
- "sliding", "moving average", "k elements"

**Problem Characteristics:**
- Need to find optimal subarray/substring
- Repeated calculations on overlapping ranges
- Constraints like "exactly k", "at most k", "at least k"
- Stream processing or sequential data

**Specific Scenarios:**
```cpp
// Fixed Window: "Maximum sum of k consecutive elements"
// Variable Window: "Longest substring with k unique characters"
// Optimization: "Minimum window containing all characters"
```

### **3. Why Use It (Advantages & Trade-offs)**

**Optimization Benefits:**
- **Time:** O(n²) → O(n) for many problems
- **Space:** Usually O(1) to O(k) auxiliary space
- **Efficiency:** Eliminates redundant calculations

**Trade-offs:**
- **Applicability:** Only works for contiguous elements
- **Complexity:** Can be tricky for beginners
- **State Management:** Need careful tracking of window properties

### **4. Types & Variations**

#### **4.1 Fixed Size Window**
```cpp
// Template for fixed window problems
int left = 0, right = 0;
while (right < n) {
    // Include right element
    
    if (right - left + 1 < k) {
        right++;  // Expand window
    }
    else if (right - left + 1 == k) {
        // Process window of size k
        // Store/update answer
        
        // Slide window
        left++;
        right++;
    }
}
```

#### **4.2 Variable Size Window**
```cpp
// Template for variable window problems
int left = 0, right = 0;
while (right < n) {
    // Include right element
    
    // Shrink window if invalid
    while (window_invalid) {
        // Remove left element
        left++;
    }
    
    // Update answer if valid
    if (window_valid) {
        ans = max(ans, right - left + 1);
    }
    
    right++;
}
```

### **5. Implementation Details**

#### **5.1 Maximum Sum Subarray of Size K (Fixed Window)**
```cpp
class Solution {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        
        int sum = 0;
        // Calculate first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        
        // Slide window: remove left, add right
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
// Time: O(n), Space: O(1)
```

#### **5.2 Longest Substring with K Unique Characters (Variable Window)**
```cpp
class Solution {
public:
    int longestKSubstr(string& s, int k) {
        if (k == 0) return 0;
        
        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int maxLen = -1;
        
        while (right < s.size()) {
            // Expand window
            freq[s[right]]++;
            
            // Shrink if too many unique chars
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            
            // Update answer when exactly k unique
            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
            
            right++;
        }
        
        return maxLen;
    }
};
// Time: O(n), Space: O(k)
```

#### **5.3 First Negative in Every Window of Size K**
```cpp
class Solution {
public:
    vector<int> firstNegative(vector<int>& nums, int k) {
        queue<int> negatives;  // Store negative numbers
        vector<int> result;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            // Store negative numbers in queue
            if (nums[right] < 0) {
                negatives.push(nums[right]);
            }
            
            // When window size reached
            if (right - left + 1 == k) {
                // First negative or 0
                if (!negatives.empty()) {
                    result.push_back(negatives.front());
                } else {
                    result.push_back(0);
                }
                
                // Remove element going out of window
                if (nums[left] < 0 && !negatives.empty()) {
                    negatives.pop();
                }
                
                left++;  // Slide window
            }
        }
        
        return result;
    }
};
```

### **6. Problem-Solving Framework**

#### **Decision Tree:**
```
Is the problem about subarrays/substrings?
├─ YES: Continue
└─ NO: Consider other patterns

Is window size fixed?
├─ YES: Use Fixed Window Template
│   └─ Track: sum, max, min, count
└─ NO: Use Variable Window Template
    └─ Track: condition satisfaction

Need to find optimal (max/min)?
├─ YES: Update answer when condition met
└─ NO: Count valid windows
```

#### **Complete Example: Subarray Sum Equals K**
```cpp
// Problem: Count subarrays with sum equal to k
// Note: Sliding window only works for non-negative arrays

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Optimal: Prefix Sum + HashMap approach
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Base case
        
        int count = 0, sum = 0;
        
        for (int num : nums) {
            sum += num;
            
            // Check if (sum - k) exists
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            
            prefixCount[sum]++;
        }
        
        return count;
    }
};
// Time: O(n), Space: O(n)

// For non-negative arrays only:
class SlidingWindowSolution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left = 0, sum = 0, count = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            
            // Shrink window if sum exceeds k
            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }
            
            if (sum == k) count++;
        }
        
        return count;
    }
};
```

### **7. Practice Problems**

#### **Easy:**
- [Maximum Sum Subarray of Size K](https://practice.geeksforgeeks.org/problems/maximum-sum-subarray-of-size-k5313/1) - Basic fixed window
- [First Negative Number in Window](https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1) - Queue management

#### **Medium:**
- [Longest Substring with K Unique Characters](https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1) - Variable window
- [Count Anagram Occurrences](https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839) - Frequency matching
- [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) - Deque optimization

#### **Hard:**
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) - Complex state tracking
- [Longest Substring Without Repeating](https://leetcode.com/problems/longest-substring-without-repeating-characters/) - Unique elements

### **8. Pro Tips & Insights**

**Competition Optimizations:**
```cpp
// Fast I/O for competitive programming
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Use arrays instead of maps when possible
int freq[26] = {0};  // For lowercase letters
```

**Common Pitfalls:**
- **Off-by-one errors:** Always check `right - left + 1`
- **Window validation:** Ensure condition checking is correct
- **Edge cases:** Empty arrays, single elements, k > n

**Template Shortcuts:**
```cpp
// Macro for sliding window problems
#define WINDOW_SIZE (right - left + 1)

// Quick frequency map operations
freq[c]++;
if (--freq[c] == 0) freq.erase(c);
```

---

## **Linear Search & Array Operations**

### **1. Core Concept & Definition**

**What it is:** Sequential search through array elements to find a target value.

**Properties:**
- **Sequential Access:** Elements checked one by one
- **No Prerequisites:** Works on unsorted arrays
- **Early Termination:** Stops when element found
- **Linear Time:** O(n) worst-case complexity

### **2. When to Use**

**Immediate Triggers:**
- Unsorted array/list
- Simple element lookup
- First/last occurrence needed
- Small dataset (n < 100)

**Avoid When:**
- Large sorted arrays (use binary search)
- Frequent searches (use hash table)
- Multiple queries (preprocess data)

### **3. Implementation**

```cpp
class LinearSearch {
public:
    // Basic linear search
    int search(vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;  // Return index
            }
        }
        return -1;  // Not found
    }
    
    // Find all occurrences
    vector<int> searchAll(vector<int>& arr, int target) {
        vector<int> indices;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                indices.push_back(i);
            }
        }
        return indices;
    }
    
    // Search with predicate
    template<typename Predicate>
    int searchIf(vector<int>& arr, Predicate pred) {
        for (int i = 0; i < arr.size(); i++) {
            if (pred(arr[i])) {
                return i;
            }
        }
        return -1;
    }
};

// Usage examples
LinearSearch searcher;
vector<int> arr = {1, 3, 5, 7, 9};

// Basic search
int idx = searcher.search(arr, 5);  // Returns 2

// Search for even number
int evenIdx = searcher.searchIf(arr, [](int x) { return x % 2 == 0; });
```

---

## **Circular Array & Queue Operations**

### **1. Core Concept & Definition**

**What it is:** Array-based data structure where the end connects back to the beginning, forming a logical circle.

**Key Properties:**
- **Modular Arithmetic:** `(index + 1) % capacity` for wraparound
- **Space Efficiency:** Fixed memory usage
- **Queue Implementation:** Natural fit for circular buffers

**Memory Layout:**
```
Logical:  [0] [1] [2] [3] [0] [1] [2] ...
Physical: [a] [b] [c] [d]
Indices:   0   1   2   3
```

### **2. Implementation Details**

```cpp
class CircularQueue {
private:
    vector<int> buffer;
    int capacity;
    int head;     // Points to first element
    int tail;     // Points to next insertion position
    
public:
    CircularQueue(int k) : capacity(k + 1), buffer(k + 1), head(0), tail(0) {
        // Reserve one extra slot to distinguish full/empty
    }
    
    bool isEmpty() {
        return head == tail;
    }
    
    bool isFull() {
        return (tail + 1) % capacity == head;
    }
    
    bool enqueue(int value) {
        if (isFull()) return false;
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }
    
    bool dequeue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        return true;
    }
    
    int front() {
        return isEmpty() ? -1 : buffer[head];
    }
    
    int rear() {
        return isEmpty() ? -1 : buffer[(tail - 1 + capacity) % capacity];
    }
    
    int size() {
        return (tail - head + capacity) % capacity;
    }
};
```

### **3. Advanced Applications**

```cpp
// Circular array rotation
void rotateRight(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;  // Handle k > n
    
    // Method 1: Using extra space
    vector<int> temp(arr);
    for (int i = 0; i < n; i++) {
        arr[(i + k) % n] = temp[i];
    }
}

// In-place rotation using reversal
void rotateRightInPlace(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    
    reverse(arr.begin(), arr.end());           // Reverse entire array
    reverse(arr.begin(), arr.begin() + k);    // Reverse first k elements
    reverse(arr.begin() + k, arr.end());      // Reverse remaining elements
}
```

---

## **Number Theory Problems**

### **1. Core Concepts**

**Special Number Types:**
- **Armstrong:** Sum of digits^(digit_count) equals original
- **Perfect:** Sum of proper divisors equals number
- **Palindrome:** Reads same forwards/backwards
- **Automorphic:** Square ends with the number itself
- **Strong:** Sum of factorial of digits equals number
- **Magic:** Custom mathematical property

### **2. Pattern Recognition**

**Common Keywords:**
- "Sum of digits", "factorial of digits"
- "Square of number", "proper divisors"
- "Reverse of number", "palindrome"
- "Special property", "mathematical condition"

### **3. Implementation Templates**

#### **3.1 Armstrong Number**
```cpp
class ArmstrongChecker {
private:
    int countDigits(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    
    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }
    
public:
    bool isArmstrong(int n) {
        int original = n;
        int digits = countDigits(n);
        int sum = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sum += power(digit, digits);
            n /= 10;
        }
        
        return sum == original;
    }
};

// Example: 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
```

#### **3.2 Perfect Number**
```cpp
class PerfectChecker {
public:
    bool isPerfect(int n) {
        if (n <= 1) return false;
        
        int sum = 1;  // 1 is always a divisor
        
        // Check divisors up to sqrt(n)
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                sum += i;
                // Add corresponding divisor if different
                if (i != n / i) {
                    sum += n / i;
                }
            }
        }
        
        return sum == n;
    }
};

// Example: 6 = 1 + 2 + 3 = 6 ✓ (divisors: 1, 2, 3)
```

#### **3.3 Palindrome Number**
```cpp
class PalindromeChecker {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        
        int reversedHalf = 0;
        
        // Reverse only half the digits
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // For even digits: x == reversedHalf
        // For odd digits: x == reversedHalf / 10 (ignore middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

// Time: O(log n), Space: O(1)
```

#### **3.4 Automorphic Number**
```cpp
class AutomorphicChecker {
public:
    bool isAutomorphic(int n) {
        int square = n * n;
        int temp = n;
        
        // Check if square ends with n
        while (temp > 0) {
            if (square % 10 != temp % 10) {
                return false;
            }
            square /= 10;
            temp /= 10;
        }
        
        return true;
    }
};

// Example: 76² = 5776, ends with 76 ✓
```

#### **3.5 Strong Number**
```cpp
class StrongChecker {
private:
    vector<int> factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    
public:
    bool isStrong(int n) {
        int original = n;
        int sum = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sum += factorial[digit];
            n /= 10;
        }
        
        return sum == original;
    }
};

// Example: 145 = 1! + 4! + 5! = 1 + 24 + 120 = 145 ✓
```

### **4. Optimization Techniques**

**Precomputation:**
```cpp
// Precompute factorials for digits 0-9
vector<int> digitFactorials = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

// Precompute powers for small bases
vector<vector<int>> powers(10, vector<int>(10));
for (int base = 0; base < 10; base++) {
    powers[base][0] = 1;
    for (int exp = 1; exp < 10; exp++) {
        powers[base][exp] = powers[base][exp-1] * base;
    }
}
```

**Digit Extraction Patterns:**
```cpp
// Fast digit extraction
template<typename Func>
void processDigits(int n, Func process) {
    while (n > 0) {
        process(n % 10);
        n /= 10;
    }
}

// Usage
int sum = 0;
processDigits(123, [&](int digit) { sum += digit; });
```

---

## **Quick Reference Tables**

### **Time Complexity Comparison**

| Algorithm/Pattern | Best Case | Average Case | Worst Case | Space |
|-------------------|-----------|--------------|------------|-------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Sliding Window (Fixed) | O(n) | O(n) | O(n) | O(1) |
| Sliding Window (Variable) | O(n) | O(n) | O(n) | O(k) |
| Circular Queue Ops | O(1) | O(1) | O(1) | O(k) |
| Number Theory Checks | O(log n) | O(log n) | O(√n) | O(1) |

### **Pattern Selection Guide**

| Problem Type | Best Pattern | Key Indicators |
|--------------|--------------|----------------|
| Subarray/Substring | Sliding Window | "contiguous", "k elements", "window" |
| Element Search | Linear/Binary Search | "find element", "search", "lookup" |
| Buffer/Queue | Circular Array | "fixed size", "FIFO", "stream processing" |
| Mathematical Properties | Number Theory | "special number", "digit manipulation" |

### **Common Pitfalls & Solutions**

| Pitfall | Problem | Solution |
|---------|---------|----------|
| Off-by-one | Window size calculation | Use `right - left + 1` |
| Integer Overflow | Large number operations | Use `long long` or modular arithmetic |
| Empty Containers | Queue operations on empty | Always check `isEmpty()` first |
| Negative Numbers | Modular arithmetic | Use `((a % n) + n) % n` |

---

## **Debugging Strategies**

### **Common Debug Techniques**

```cpp
// 1. Print window state
void debugWindow(int left, int right, const vector<int>& arr) {
    cout << "Window [" << left << ", " << right << "]: ";
    for (int i = left; i <= right; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 2. Trace algorithm steps
#ifdef DEBUG
#define DBG(x) cout << #x << " = " << x << endl
#else
#define DBG(x)
#endif

// 3. Validate invariants
void validateWindow(int left, int right, int n) {
    assert(0 <= left && left <= right && right < n);
    assert(right - left + 1 >= 0);  // Non-negative size
}
```

### **Test Case Generation**

```cpp
// Generate edge cases for testing
vector<vector<int>> generateTestCases() {
    return {
        {},                    // Empty array
        {1},                   // Single element
        {1, 2},                // Two elements
        {1, 1, 1, 1},         // All same
        {1, 2, 3, 4, 5},      // Ascending
        {5, 4, 3, 2, 1},      // Descending
        {1, 3, 2, 5, 4}       // Random
    };
}
```

---

## **Performance Benchmarks**

### **Input Size Recommendations**

| Pattern | Small (n < 10³) | Medium (n < 10⁶) | Large (n < 10⁹) |
|---------|-----------------|-------------------|------------------|
| Linear Search | ✓ | ⚠️ | ❌ |
| Sliding Window | ✓ | ✓ | ✓ |
| Circular Queue | ✓ | ✓ | ✓ |
| Number Theory | ✓ | ✓ | ✓ |

### **Memory Usage Guidelines**

```cpp
// Memory-efficient alternatives
// Instead of: unordered_map<char, int> freq;
int freq[26] = {0};  // For lowercase letters only

// Instead of: vector<int> window;
// Use: two pointers with original array

// For large k: consider segment trees or sparse tables
```

---

## **Cross-Reference Patterns**

### **Pattern Relationships**

```
Sliding Window ←→ Two Pointers
    ↓
Subarray Problems ←→ Prefix Sums
    ↓
Dynamic Programming ←→ Optimization Problems

Linear Search ←→ Binary Search
    ↓
Search Problems ←→ Hash Tables
    ↓
Lookup Optimization ←→ Preprocessing

Circular Arrays ←→ Modular Arithmetic
    ↓
Queue/Buffer ←→ Deque Operations
    ↓
Stream Processing ←→ Sliding Window
```

### **When to Transition**

- **Linear → Binary Search:** When array is sorted
- **Sliding Window → DP:** When overlapping subproblems exist
- **Array → Hash Table:** When frequent lookups needed
- **Simple Math → Number Theory:** When special properties required

---

*This reference guide serves as a comprehensive knowledge base for mastering DSA patterns. Each section builds upon fundamental concepts while providing practical, competition-ready implementations.*