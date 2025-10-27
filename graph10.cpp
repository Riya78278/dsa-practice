//Shortest Path in Weighted undirected graph
#include<iostream>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it=pq.top();
            int distance=it.first;
            int node=it.second;
            pq.pop();
            
            for(auto itt :adj[node]){
                int adjnode=itt.first;
                int adjweight=itt.second;
                
                if(distance+adjweight <dist[adjnode]){
                    dist[adjnode]=distance +adjweight;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        //int count=1;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
            //count++;
        }
        path.push_back(1);
        
        reverse(path.begin(),path.end());
        path.insert(path.begin(), dist[n]);
        return path ;
    }
};