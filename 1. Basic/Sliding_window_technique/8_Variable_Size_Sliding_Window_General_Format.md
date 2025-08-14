## Sliding Window Technique: General Formats

### 1. Fixed Size Sliding Window

```cpp
int left = 0, right = 0;

while (right < size) {
    // Include current element in window calculation
    // e.g., sum += arr[right];

    int windowSize = right - left + 1;

    if (windowSize < k) {
        // Expand the window
        right++;
    }
    else if (windowSize == k) {
        // Perform required operation on the window
        // e.g., ans = max(ans, sum);

        // Slide the window:
        // - Remove the element going out of the window
        // - Maintain window size
        // e.g., sum -= arr[left];
        left++;
        right++;
    }
}
```

---

### 2. Variable Size Sliding Window

```cpp
int left = 0, right = 0;

while (right < size) {
    // Include current element in window calculation
    // e.g., sum += arr[right];

    // Check the condition based on the problem statement
    if (condition < k) {
        // Expand the window
        right++;
    }
    else if (condition == k) {
        // Perform required operation on the window
        // e.g., ans = max(ans, sum);

        // Optionally slide the window
        // e.g., sum -= arr[left];
        left++;
    }
    else if (condition > k) {
        while (condition > k) {
            // Remove calculation for left
            // e.g., sum -= arr[left];
            left++;
        }
    }
    right++;
}
```

**Notes:**
- Replace `condition` and `k` with the specific logic required by your problem.
- Use comments to clarify window operations and calculations.
- The fixed size format maintains a window of size `k`, while the variable size format adapts based on a condition.