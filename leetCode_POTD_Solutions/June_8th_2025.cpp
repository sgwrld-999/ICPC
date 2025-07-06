#include <iostream>
#include <vector>
using namespace std;

/*
To visualise how to solve the problem. Observe the pattern. The pattern was, we need the lexographical order, we are more or like adding terms on the right, or we can say appending:
For n = 15
"1" -> acceptable 
"1" + "0" -> acceptable as 10 < 15 
"1" + "0" + "0" -> not acceptable as 100 > 15 out of bound
"1" + "1" -> acceptable as 11 < 15
.
.
.

Similarly for 2,3,4,5....9 as 10,11,12,.. all the valid inputs will be already in the range.

The data-structure is using here is the trees.
*/


class Solution {
public:
    void dfsLexicalOrder(int n, vector<int>& result, int currNum) {
        if (currNum > n) return;

        result.push_back(currNum);
        for (int i = 0; i <= 9; ++i) {
            int nextNum = currNum * 10 + i;
            if (nextNum > n) return;
            dfsLexicalOrder(n, result, nextNum);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int start = 1; start <= 9; ++start) {
            dfsLexicalOrder(n, result, start);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<int> res = sol.lexicalOrder(n);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
}

