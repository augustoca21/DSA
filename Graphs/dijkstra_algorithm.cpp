// dijkstra_algorithm.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> PII;

vector<int> dijkstra(int start, const vector<vector<PII>>& adj) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<PII>> adj(n);

    // Grafo dirigido con pesos positivos
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 2});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 9});

    vector<int> distances = dijkstra(0, adj);

    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from 0 to " << i << ": " << distances[i] << endl;
    }

    return 0;
}
