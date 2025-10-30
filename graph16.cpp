//Minimum Spanning Tree

#include <iostream>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // because undirected
        }

        // Step 2: Min-heap for {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0;

        pq.push({0, 0}); // start with node 0, weight 0

        // Step 3: Prim's Algorithm
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;
                if (!vis[adjNode]) {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return sum;
    }
};


