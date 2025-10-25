//Eventual Safe States
#include <iostream>
using namespace std;
class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<int>&vis, vector<int>&pathvis, vector<int>&check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,check)==true){
                    check[node]=0;
                    return true;
                    
                }
                
            }
            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        vector<int>safearray;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
                
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safearray.push_back(i);
            }
        }
        return safearray;
    }
};
