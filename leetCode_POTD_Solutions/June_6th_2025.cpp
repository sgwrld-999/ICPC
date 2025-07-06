#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        stack<char> st;
        string res = "";

        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            char nextMin = (i + 1 < n) ? minSuffix[i + 1] : CHAR_MAX;

            while (!st.empty() && st.top() <= nextMin) {
                res += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    string str1;
    cin >> str1;

    Solution sol;
    string res = sol.robotWithString(str1);
    cout << res << endl;
}
