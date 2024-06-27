#include<bits/stdc++.h>
using namespace std;

/* Problem: Kefa and Park
   Link: https://codeforces.com/problemset/problem/580/C */

void dfs(int node, int m, vector<int>& cats, vector<vector<int>>& graph, vector<int>& visited, int numberOfCats, int& ans) {
    visited[node] = 1;
    if (cats[node] == 1) {
        numberOfCats++;
    } else {
        numberOfCats = 0;
    }
    if (numberOfCats > m) return;

    bool isLeaf = true;
    for (auto child : graph[node]) {
        if (!visited[child]) {
            isLeaf = false;
            dfs(child, m, cats, graph, visited, numberOfCats, ans);
        }
    }
    if (isLeaf) {
        ans++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cats(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = 0;
    vector<int> visited(n + 1, 0);
    dfs(1, m, cats, graph, visited, 0, ans);
    cout << ans << endl;
    return 0;
}
