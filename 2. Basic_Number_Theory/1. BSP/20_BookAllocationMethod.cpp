#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Allocate n books to m students such that maximum pages assigned to any student is minimized
 *    - Books must be allocated in contiguous manner (can't skip books)
 *    - Each student gets at least one book
 *    - Classic "minimize the maximum" optimization problem
 * 
 * 2. **Key Insight**: 
 *    - Similar to Split Array problem - we're partitioning array into m parts
 *    - Want to minimize the maximum sum (pages) in any partition
 *    - Binary search on answer: "Can m students handle books with max pages ≤ target?"
 * 
 * 3. **Binary Search on Answer**:
 *    - Lower bound: max(pages) (student with heaviest single book)
 *    - Upper bound: sum(pages) (one student gets all books)
 *    - For each candidate max pages, check if allocation is possible
 * 
 * 4. **Validation Function (Greedy)**:
 *    - Assign books to students greedily
 *    - Give current student books until adding next book exceeds limit
 *    - Then move to next student
 *    - Count total students needed
 *    - If students needed ≤ m, allocation is possible
 * 
 * 5. **Why Greedy Works**:
 *    - If allocation with max pages ≤ target is possible, greedy finds it
 *    - Delaying assignment to next student only increases total students needed
 *    - Greedy minimizes number of students required
 * 
 * 6. **Relationship to Other Problems**:
 *    - Book Allocation ≡ Split Array Maximum Sum
 *    - Painter's Partition ≡ Same pattern
 *    - Ship Capacity ≡ Similar but with time constraint
 * 
 * 7. **Edge Cases**:
 *    - m > n: impossible to give each student at least one book
 *    - m = 1: one student gets all books (return total pages)
 *    - m = n: each student gets exactly one book (return max pages)
 * 
 * 8. **Complexity**:
 *    - Time: O(n * log(sum - max)) - binary search with linear validation
 *    - Space: O(1) - constant extra space
 */

class Solution {
public:
    // Check if m students can handle books with max pages <= maxPages
    bool canAllocate(vector<int>& books, int students, int maxPages) {
        int studentsUsed = 1;
        int currentPages = 0;
        
        for (int pages : books) {
            if (pages > maxPages) return false; // Single book exceeds limit
            
            if (currentPages + pages <= maxPages) {
                currentPages += pages;
            } else {
                // Assign to next student
                studentsUsed++;
                currentPages = pages;
                if (studentsUsed > students) return false;
            }
        }
        
        return true;
    }
    
    int allocateBooks(vector<int>& books, int students) {
        int n = books.size();
        if (students > n) return -1; // Impossible
        
        int low = *max_element(books.begin(), books.end());
        int high = accumulate(books.begin(), books.end(), 0);
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (canAllocate(books, students, mid)) {
                high = mid; // Try smaller maximum pages
            } else {
                low = mid + 1; // Need more pages per student
            }
        }
        
        return low;
    }
};

int main() {
    int n, m;
    cin >> n;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    cin >> m;
    
    Solution obj;
    int result = obj.allocateBooks(books, m);
    if (result == -1) {
        cout << "Allocation not possible" << endl;
    } else {
        cout << "Minimum possible maximum pages: " << result << endl;
    }
    
    return 0;
}

/*
Test Cases:
Input:
4
12 34 67 90
2
Output: 113
Explanation: Allocation [12, 34, 67] and [90] gives max pages 113 and 90 respectively.

Input:
5
10 20 30 40 50
3
Output: 60
Explanation: Allocation [10, 20, 30], [40], [50] gives max pages 60, 40, 50 respectively.
*/
