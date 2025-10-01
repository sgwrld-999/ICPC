# Complete Binary Search Pattern (BSP) Reference Guide
*A comprehensive production-ready knowledge base for mastering binary search algorithms and patterns*

---

## **Binary Search - Core Pattern**

### **1. Core Concept & Definition**
- **Definition:** Efficient search algorithm that repeatedly divides a sorted array in half to locate a target element
- **Fundamental Property:** Eliminates half the search space at each step by comparing with middle element
- **Memory Representation:** Works on any random-access data structure (arrays, vectors)
- **Key Invariant:** Search space maintains sorted order throughout the algorithm

**Time Complexity:** O(log n) | **Space Complexity:** O(1) iterative, O(log n) recursive

### **2. When to Use (Pattern Recognition Triggers)**

**Immediate Keywords:**
- "Sorted array", "find element", "search position"
- "O(log n) time complexity", "divide and conquer"
- "Find first/last occurrence", "insertion point"

**Problem Characteristics:**
- Array/list is sorted (or can be treated as sorted)
- Need to find specific element or position
- Large dataset where linear search is inefficient
- Range queries or boundary detection needed

**Specific Scenarios:**
- Database index searches
- Library catalog lookups
- Finding version numbers in sorted releases
- Debugging: locate problematic code segment in sorted commits

### **3. Why Use It (Advantages & Trade-offs)**
- **Optimization:** Reduces O(n) linear search to O(log n)
- **Efficiency:** Minimal memory footprint with iterative implementation
- **Scalability:** Performance gap widens dramatically with larger datasets
- **Trade-off:** Requires sorted data (sorting cost if not pre-sorted)

### **4. Types & Variations**
```
Standard Binary Search: Find exact element
Lower Bound: First element >= target  
Upper Bound: First element > target
Search Insert Position: Where to insert target
Binary Search on Answer: Search for optimal value in range
Rotated Array Search: Modified BS for rotated sorted arrays
```

### **5. Implementation Details**

**Core Template (Iterative - Recommended)**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents overflow
        
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;  // Not found
}
// Time: O(log n), Space: O(1)
```

**Recursive Implementation**
```cpp
int binarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) 
        return binarySearchRecursive(arr, mid + 1, high, target);
    else 
        return binarySearchRecursive(arr, low, mid - 1, target);
}
// Time: O(log n), Space: O(log n)
```

### **6. Problem-Solving Framework**

**Decision Tree:**
1. Is array sorted? → Standard Binary Search
2. Need insertion point? → Lower Bound pattern
3. Find range of elements? → Lower + Upper Bound
4. Array rotated? → Modified Binary Search
5. Optimization problem? → Binary Search on Answer

---

## **Lower Bound Pattern**

### **1. Core Concept**
- **Definition:** Find the first index where `arr[i] >= target`
- **Key Property:** Returns insertion point to maintain sorted order
- **Boundary:** If no valid index exists, returns array size or -1

### **2. When to Use**
**Triggers:**
- "Insert to maintain sorted order"
- "First element greater than or equal to X"
- "Lower limit of range"

### **3. Implementation**
```cpp
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = arr.size();  // Default: insert at end
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= target) {
            result = mid;      // Potential answer
            high = mid - 1;    // Search left for smaller index
        } else {
            low = mid + 1;     // Search right
        }
    }
    
    return result;
}
```

---

## **Upper Bound Pattern**

### **1. Core Concept**
- **Definition:** Find the first index where `arr[i] > target`
- **Key Property:** Points to element after last occurrence of target
- **Usage:** Combined with lower bound to find element ranges

### **2. Implementation**
```cpp
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int result = arr.size();
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] > target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}
```

---

## **Binary Search on Answer Pattern**

### **1. Core Concept**
- **Definition:** Use binary search to find optimal value in a continuous range
- **Key Insight:** When direct computation is hard, but validation is easy
- **Pattern:** "Minimize maximum" or "Maximize minimum" problems

### **2. When to Use**
**Triggers:**
- "Find minimum time/cost/distance such that..."
- "What's the maximum capacity/speed that allows..."
- "Allocate resources optimally"
- Optimization problems with monotonic properties

### **3. Template**
```cpp
bool canAchieve(int value, /* other params */) {
    // Check if 'value' is achievable
    // Return true if possible, false otherwise
}

int binarySearchOnAnswer(int low, int high /* other params */) {
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canAchieve(mid /* other params */)) {
            result = mid;      // Current answer is valid
            high = mid - 1;    // Try to find better (smaller)
        } else {
            low = mid + 1;     // Need larger value
        }
    }
    
    return result;
}
```

### **4. Classic Problems & Solutions**

**Template 1: Koko Eating Bananas**
```cpp
bool canFinish(vector<int>& piles, int speed, int hours) {
    int totalTime = 0;
    for (int pile : piles) {
        totalTime += (pile + speed - 1) / speed;  // Ceiling division
        if (totalTime > hours) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int H) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canFinish(piles, mid, H)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}
// Time: O(n * log(max_pile))
```

**Template 2: Split Array Largest Sum**
```cpp
bool canSplit(vector<int>& nums, int k, int maxSum) {
    int subarrays = 1, currentSum = 0;
    
    for (int num : nums) {
        if (num > maxSum) return false;
        
        if (currentSum + num <= maxSum) {
            currentSum += num;
        } else {
            subarrays++;
            currentSum = num;
            if (subarrays > k) return false;
        }
    }
    
    return true;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, k, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
}
```

---

## **Rotated Array Search Pattern**

### **1. Core Concept**
- **Definition:** Search in sorted array that has been rotated at unknown pivot
- **Key Property:** One half is always sorted in rotated array
- **Strategy:** Identify sorted half, determine if target lies in that range

### **2. Implementation**
```cpp
int searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}
```

**With Duplicates (Handle Edge Case):**
```cpp
int searchRotatedWithDuplicates(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) return mid;
        
        // Handle duplicates: trim search space
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue;
        }
        
        // Rest of standard rotated search logic...
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    return -1;
}
```

---

## **Peak Element Pattern**

### **1. Core Concept**
- **Definition:** Find element greater than both neighbors
- **Key Property:** Array boundaries treated as negative infinity
- **Strategy:** Use slope direction to eliminate half

### **2. Implementation**
```cpp
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n-1;
    
    int low = 1, high = n - 2;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid] > nums[mid-1]) {
            low = mid + 1;  // Ascending slope, peak ahead
        } else {
            high = mid - 1; // Descending slope, peak behind
        }
    }
    
    return -1;
}
```

---

## **Square Root & Nth Root Pattern**

### **1. Core Concept**
- **Definition:** Find integer square root without using built-in functions
- **Strategy:** Binary search on answer space [1, x]

### **2. Implementation**
```cpp
int mySqrt(int x) {
    if (x < 2) return x;
    
    int low = 1, high = x / 2;  // Optimization: sqrt(x) <= x/2 for x > 4
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = (long long)mid * mid;
        
        if (square == x) return mid;
        else if (square < x) low = mid + 1;
        else high = mid - 1;
    }
    
    return high;  // Floor of sqrt(x)
}
```

**Nth Root Extension:**
```cpp
int nthRoot(int n, int m) {
    int low = 1, high = m;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long power = 1;
        
        // Calculate mid^n with overflow check
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break;
        }
        
        if (power == m) return mid;
        else if (power < m) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;  // Exact nth root doesn't exist
}
```

---

## **2D Matrix Search Pattern**

### **1. Core Concept**
- **Definition:** Search in 2D matrix with sorted rows and columns
- **Strategy:** Treat as flattened sorted array

### **2. Implementation**
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / n, col = mid % n;
        int midValue = matrix[row][col];
        
        if (midValue == target) return true;
        else if (midValue < target) low = mid + 1;
        else high = mid - 1;
    }
    
    return false;
}
// Time: O(log(m*n)), Space: O(1)
```

---

## **Complexity Analysis Quick Reference**

| Pattern | Time Complexity | Space Complexity | Use Case |
|---------|----------------|------------------|----------|
| Standard Binary Search | O(log n) | O(1) | Find element |
| Lower/Upper Bound | O(log n) | O(1) | Range queries |
| Binary Search on Answer | O(log(range) * validation) | O(1) | Optimization |
| Rotated Array | O(log n) | O(1) | Modified sorted array |
| 2D Matrix | O(log(m*n)) | O(1) | 2D search space |
| Peak Finding | O(log n) | O(1) | Local maximum |

---

## **Practice Problems by Difficulty**

### **Easy**
1. [Binary Search](https://leetcode.com/problems/binary-search/) - Template practice
2. [Search Insert Position](https://leetcode.com/problems/search-insert-position/) - Lower bound
3. [Sqrt(x)](https://leetcode.com/problems/sqrtx/) - Binary search on answer

### **Medium**
1. [Search in Rotated Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
2. [Find Peak Element](https://leetcode.com/problems/find-peak-element/)
3. [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
4. [Capacity to Ship Packages](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
5. [Split Array Largest Sum](https://leetcode.com/problems/split-largest-sum/)

### **Hard**
1. [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
2. [Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)
3. [Aggressive Cows](https://www.spoj.com/problems/AGGRCOW/)

---

## **Pro Tips & Competition Insights**

### **🔥 Critical Optimizations**
1. **Overflow Prevention**: Always use `mid = low + (high - low) / 2`
2. **Precision for Doubles**: Use `while(high - low > 1e-9)` instead of equality
3. **Search Space**: Carefully define bounds - often determines correctness

### **🚨 Common Pitfalls**
- **Infinite Loops**: Wrong update conditions (`low = mid` vs `low = mid + 1`)
- **Off-by-One**: Boundary handling in range updates
- **Integer Overflow**: Large number calculations (use `long long`)

### **⚡ Template Selection Guide**
```cpp
// For "minimize maximum" problems
while (low < high) {
    int mid = low + (high - low) / 2;
    if (canAchieve(mid)) high = mid;
    else low = mid + 1;
}

// For "maximize minimum" problems  
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (canAchieve(mid)) {
        answer = mid;
        low = mid + 1;
    } else high = mid - 1;
}
```

### **🎯 Competition Shortcuts**
- **Quick Check**: Verify with small test cases first
- **Edge Cases**: Test with arrays of size 1, 2, empty
- **Debugging**: Print search space bounds for complex problems
- **Time Saving**: Use STL `lower_bound()` and `upper_bound()` when allowed

---

## **Related Patterns Cross-Reference**
- **Binary Search** ↔ **Two Pointers** (sorted array problems)
- **Binary Search** ↔ **Divide & Conquer** (problem decomposition)
- **Binary Search** ↔ **Dynamic Programming** (optimization problems)
- **Binary Search** ↔ **Greedy** (validation functions in "search on answer")

*Master binary search and unlock efficient solutions to optimization, searching, and range-based algorithmic challeng