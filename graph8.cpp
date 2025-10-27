// Dijkstra Algorithm using priority queue
# include<iostream>
using namespace std;
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjweight=it.second;
                
                if(distance+adjweight < dist[adjnode]){
                    dist[adjnode]=distance+adjweight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};