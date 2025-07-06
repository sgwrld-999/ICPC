#include <bits/stdc++.h>
using namespace std;

/*
 💭 Thought Process:
 The problem requires that every time we encounter a '*', we must remove (i.e., eliminate) the lexicographically smallest character to the left of that star.
 This implies that for every '*', we need to search for the smallest character among all characters before it — and this needs to be done repeatedly, potentially many times.

 ✅ Possible Solutions:
 1. Brute Force Approach:
 For every '*' encountered:

 Scan all characters to its left (that haven’t been removed).

 Find the smallest character and its index.

 Mark it as removed (e.g., replace it with '*' or use a boolean array).

 Time Complexity: O(n²) in the worst case, especially if many '*' characters appear.

 Drawback: Inefficient for large strings with many stars, as it rescans repeatedly.

 2. Optimized Approach with Data Structure:
 Use a priority queue (min-heap) or balanced BST to always keep track of the smallest valid characters (along with their indices).

 For each character:

 If it's not a '*', insert it into the structure.

 If it is a '*', remove the smallest character seen so far and mark it.

 Time Complexity: O(n log n) due to insertions and deletions in the heap.

 Trade-off: Slightly more complex logic, but scales better.

 📝 Interview Tip:
 Mention that although a stack works for a "last in, first out" character removal (like backspace logic), here we need to remove the smallest character, not the last — hence a priority queue or custom data structure is more suitable.


 */
 class Solution {
public:
    typedef pair<char, int> P;

    struct comp {
        bool operator()(P &p1, P &p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    string cleanStars(string s) {
        int n = s.length();
        priority_queue<P, vector<P>, comp> pq;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                if (!pq.empty()) {
                    int idx = pq.top().second;
                    pq.pop();
                    s[idx] = '*'; // mark removed
                }
            }
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};

int main() {
    string str1;
    cin >> str1;
    Solution sol;
    string res = sol.cleanStars(str1);
    cout << res << endl;
}
