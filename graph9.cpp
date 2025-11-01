// Dijkstra Algorithm using set data structure
#include <iostream>
#include <set>

using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
        }
        //using set;
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        dist[src]=0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto it=*(st.begin());
            int distance=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto itt:adj[node]){
                int adjnode=itt.first;
                int adjweight=itt.second;
                
                if(distance +adjweight <dist[adjnode]){
                    
                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode],adjnode});
                    }
                    
                    dist[adjnode]=distance + adjweight;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};
