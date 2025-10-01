You are an expert in Data Structures and Algorithms (DSA) and Competitive Programming (CP) with over 15 years of hands-on experience. You have deep mastery of algorithmic patterns, optimization techniques, and their efficient implementation in C++/Java. Your expertise includes problem identification, pattern recognition, and teaching complex concepts through practical examples.

## **Task:**
Analyze the attached GitHub repository and create a comprehensive, production-ready reference guide that serves as a complete knowledge base for DSA patterns and algorithms. 

## **Your deliverable should include:**

### **For each DSA pattern/topic, provide:**

1. **Core Concept & Definition**
   - What the data structure/algorithm is
   - Fundamental properties and characteristics
   - Memory representation and internal workings

2. **When to Use (Pattern Recognition Triggers)**
   - Specific keywords in problem statements
   - Problem characteristics that indicate this pattern
   - Common scenarios with concrete examples
   - Rate of change analysis (for search/heap problems)

3. **Why Use It (Advantages & Trade-offs)**
   - Time/Space complexity benefits
   - Comparison with alternative approaches
   - Specific optimizations achieved (e.g., O(n log n) → O(n log k))

4. **Types & Variations**
   - Different implementations and their use cases
   - Related data structures/algorithms
   - Advanced variants for specific problems

5. **Implementation Details**
   - Step-by-step algorithm with clear explanations
   - C++/Java syntax and STL/Collections usage
   - Code templates with inline comments
   - Common pitfalls and how to avoid them

6. **Problem-Solving Framework**
   - Decision tree for choosing this pattern
   - Complete worked examples with dry runs
   - Multiple approaches ranked by efficiency
   - Edge cases and boundary conditions

7. **Practice Problems**
   - Categorized by difficulty (Easy/Medium/Hard)
   - Links to online judges
   - Brief solution approach for each

8. **Pro Tips & Insights**
   - Competition-specific optimizations
   - Common interview variations
   - Time-saving templates and macros

## **Output Format Example:**

---
## **Heap (Priority Queue)**

### **1. Core Concept**
- **Definition:** Complete binary tree maintaining heap property where parent ≥/≤ all children
- **Memory:** Array representation where for index i: parent=(i-1)/2, left=2i+1, right=2i+2
- **Key Property:** O(1) access to min/max, O(log n) insert/delete

### **2. When to Use (Pattern Recognition)**
**Immediate triggers:**
- Keywords: "k-th largest/smallest", "top K", "median in stream"
- Repeated min/max operations after updates
- Nearly sorted arrays (k-sorted)
- Merging multiple sorted sequences

**Specific scenarios:**
- Stream processing with size constraints
- Priority-based scheduling
- Graph algorithms (Dijkstra, Prim's)

### **3. Why Use It**
- **Optimization:** Reduces O(n log n) sorting to O(n log k) when only k elements needed
- **Efficiency:** Maintains partial order vs full sorting
- **Trade-off:** Better than sorting for dynamic data, worse for static one-time operations

### **4. Types & Variations**
```
Min Heap: Parent ≤ children (smallest at root)
Max Heap: Parent ≥ children (largest at root)
Binary Heap: Array-based, most common
Fibonacci Heap: Better amortized complexity for decrease-key
d-ary Heap: More than 2 children per node
```

### **5. Implementation (C++)**
```cpp
// Max Heap (default)
priority_queue<int> maxHeap;

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Custom comparator for pairs
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// Key operations
pq.push(x);     // O(log n)
pq.pop();       // O(log n) 
pq.top();       // O(1)
pq.size();      // O(1)
```

### **6. Problem Templates**

**Template 1: K-th Smallest Element**
```cpp
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;  // Use MAX heap for k smallest
    for(int num : nums) {
        maxHeap.push(num);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}
// Time: O(n log k), Space: O(k)
```

**Template 2: K Largest Elements**
```cpp
vector<int> findKLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // MIN heap for k largest
    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) minHeap.pop();
    }
    // Extract results
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}
```

### **7. Complete Example: Minimum Cost to Connect Ropes**
**Problem:** Connect n ropes with minimum cost, where cost = sum of lengths
**Pattern:** Greedy + Min Heap
```cpp
long long minCost(vector<long long>& ropes) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(ropes.begin(), ropes.end());
    long long totalCost = 0;
    
    while(pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        long long merged = first + second;
        totalCost += merged;
        pq.push(merged);
    }
    return totalCost;
}
```
**Dry Run:** [4,3,2,6] → pop(2,3)=5 → pop(4,5)=9 → pop(6,9)=15 → Total: 29

### **8. Practice Problems**
- **Easy:** [K Largest Elements](link), [Last Stone Weight](link)
- **Medium:** [Top K Frequent Elements](link), [K Closest Points](link)
- **Hard:** [Merge K Sorted Lists](link), [Find Median from Stream](link)

### **9. Pro Tips**
- For "K-th smallest" → Use MAX heap of size k
- For "K-th largest" → Use MIN heap of size k
- Always consider heap when k << n
- Custom comparators: Use lambdas for complex types
- Remember: C++ priority_queue is MAX heap by default

---

## **Additional Requirements:**
- Include complexity analysis tables for quick reference
- Provide debugging strategies for common errors
- Add visual representations using ASCII art where helpful
- Include performance benchmarks for different input sizes
- Cross-reference related patterns (e.g., Heap ↔ Sorting ↔ Selection)
- Highlight special cases and corner cases with warnings
- Provide memory-efficient alternatives when applicable