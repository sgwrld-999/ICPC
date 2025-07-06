# Intuition

To solve this problem, we need to understand the **Manhattan distance** and how direction changes impact it.

## 🔍 Observations

1. **Coordinate Mapping**

   * Start at origin (0,0)
   * Move 'E' → +1 on X-axis
   * Move 'W' → −1 on X-axis
   * Move 'N' → +1 on Y-axis
   * Move 'S' → −1 on Y-axis

2. **Manhattan Distance**

   * From origin:
     `Distance = |x| + |y|`
   * Every move shifts the current position along X or Y.

3. **Steps vs. Distance**

   * After `i+1` moves, you’ve taken `stepsTaken` steps.
   * However, the Manhattan distance might be less due to cancelling moves (e.g., ‘N’ and ‘S’ cancel).

4. **Optimization Opportunity**

   * You can flip at most `k` directions.
   * Each **flip** can potentially increase the Manhattan distance by `+2`:

     * 1: it prevents a cancelling effect
     * 2: it contributes positively in the correct direction

5. **Goal**

   * After each move, calculate the current Manhattan distance.
   * Use up to `2*k` to extend it further.
   * Track the maximum result.

---

# Approach

1. Initialize counters for all directions: `east`, `west`, `north`, `south`.
2. Traverse each character in the input string:

   * Update direction counters accordingly.
   * Compute current position: `x = east - west`, `y = north - south`
   * Compute current Manhattan distance: `abs(x) + abs(y)`
   * Calculate how many steps are *wasted* (steps not contributing to Manhattan distance).
   * You can recover at most `min(2 * k, wastedSteps)` of them.
   * Add this extra distance to the current one to get the best possible value at this point.
   * Update the running maximum distance.

---

# Complexity

* **Time complexity**: $O(n)$
  We traverse the string once and do constant work per character.

* **Space complexity**: $O(1)$
  We use only a fixed number of variables regardless of input size.

---

# Code

```cpp []
class Solution {
public:
    /**
     * @brief Computes the maximum Manhattan distance from origin (0,0)
     *        after making at most k direction changes to optimize distance.
     * 
     * @param directions A string containing only 'N', 'S', 'E', 'W'
     * @param k Maximum number of allowed direction changes
     * @return int Maximum possible Manhattan distance
     */
    int maxDistance(string directions, int k) {
        int n = directions.size();
        
        int east = 0, west = 0, north = 0, south = 0;
        int maxManhattanDistance = 0;

        for (int i = 0; i < n; ++i) {
            char move = directions[i];
            switch (move) {
                case 'E': east++; break;
                case 'W': west++; break;
                case 'N': north++; break;
                case 'S': south++; break;
                default: /* invalid input - could log or throw in production */ break;
            }

            int currentX = east - west;
            int currentY = north - south;
            int manhattanDistance = abs(currentX) + abs(currentY);

            int stepsTaken = i + 1;
            int wastedSteps = stepsTaken - manhattanDistance;

            // You can only fix at most 2*k units of distance (flipping k moves)
            int extraDistance = min(2 * k, wastedSteps);

            int optimizedDistance = manhattanDistance + extraDistance;
            maxManhattanDistance = max(maxManhattanDistance, optimizedDistance);
        }

        return maxManhattanDistance;
    }
};
```

