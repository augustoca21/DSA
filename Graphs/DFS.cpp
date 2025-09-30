// dfs_algorithm.cpp
#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6; // número de nodos numerados del 0 al 5
    vector<vector<int>> adj(n);

    // grafo no dirigido
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    vector<bool> visited(n, false);
    dfs(0, adj, visited);

    return 0;
}
