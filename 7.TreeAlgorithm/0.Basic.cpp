#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int vertices;
    cout << "Enter the number of vertices : " << endl ;
    cin >> vertices;
    vector<vector<int>> adjList(vertices);
    
    cout << "Enter edges : " << endl ;
    for(int i = 0 ; i < vertices - 1 ; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(auto vertice : adjList){
        for(auto currentVert : vertice){
            cout << currentVert << " " ;
        }
        cout << endl ;
    }
    return 0;
}

____________________________________________________________________________________________________________________________________________________________________________________
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int vertices, edges;
    cout << "Enter the number of vertices: " << endl;
    cin >> vertices;
    cout << "Enter the number of edges: " << endl;
    cin >> edges;

    vector<vector<int>> adjMatrix(vertices + 1, vector<int>(vertices + 1, 0));
    
    cout << "Enter edges (u v): " << endl;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "Adjacency Matrix: " << endl;
    for(int i = 1; i <= vertices; i++){
        for(int j = 1; j <= vertices; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
____________________________________________________________________________________________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

public:
    int findComponents(int nodes, vector<vector<int>>& adjList) {
        vector<bool> visited(nodes, false);
        int components = 0;
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adjList, visited);
            }
        }
        return components;
    }
};

int main(int argc, char const *argv[]) {
    int vertices, edges;
    cout << "Enter the number of vertices: " << endl;
    cin >> vertices;
    cout << "Enter the number of edges: " << endl;
    cin >> edges;
    
    vector<vector<int>> adjList(vertices+1);
    
    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "Adjacency List: " << endl;
    for (int i = 0; i < vertices+1; i++) {
        cout << i << ": ";
        for (auto currentVert : adjList[i]) {
            cout << currentVert << " ";
        }
        cout << endl;
    }

    Solution sol;
    int numComponents = sol.findComponents(vertices+1, adjList);
    cout << "Number of components: " << numComponents << endl;

    return 0;
}
//1 2 1 3 2 3 4 6 4 5 6 7 5 7 8 9 

