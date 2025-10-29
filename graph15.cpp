//Number of Ways to Arrive at Destination

#include <iostream>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Min-heap for Dijkstra (distance, node)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (distance > dist[node]) continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                long long adjwt = it.second;

                if (distance + adjwt < dist[adjnode]) {
                    dist[adjnode] = distance + adjwt;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                }
                else if (distance + adjwt == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};

