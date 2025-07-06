#include<bits/stdc++.h>
using namespace std;


/*
The question introduced a connection between the words using reflexivity, symmetry, and Transitivity. 
Since they are interlinked, the only data structure that can solve the problem is Graphs.
Draw the graph and see it:
Possible solution:
1. BFS
2. DFS
3. DUs

*/
class Solution {
public:
    char DFSForMinChar(vector<vector<char>> &adj, char cur, vector<int>& vis) {
        vis[cur - 'a'] = 1;
        char minChar = cur;

        for (char neighbour : adj[cur - 'a']) {
            if (!vis[neighbour - 'a']) {
                minChar = min(minChar, DFSForMinChar(adj, neighbour, vis));
            }
        }
        return minChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<char>> adj(26);

        for (int i = 0; i < s1.length(); i++) {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(s2[i]);
            adj[v].push_back(s1[i]);
        }

        string result = "";
        for (char ch : baseStr) {
            vector<int> vis(26, 0);
            char minChar = DFSForMinChar(adj, ch, vis);
            result.push_back(minChar);
        }

        return result;
    }
};

int main() {
    string str1, str2, str3;

    cout << "Enter strings s1, s2, and baseStr: ";
    cin >> str1 >> str2 >> str3;

    if (str1.length() != str2.length()) {
        cout << "Invalid input: s1 and s2 must be of equal length." << endl;
        return 1;
    }

    Solution sol;
    string res = sol.smallestEquivalentString(str1, str2, str3);
    cout << "Result: " << res << endl;

    return 0;
}