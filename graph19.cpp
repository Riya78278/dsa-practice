// Minimum Spanning Tree - Kruskal's Algorithm
#include <iostream>
using namespace std;
class DisjointSet{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n,-1);
    }
    
    int findParent(int x){
        if(parent[x]==-1) return x;
        return parent[x]=findParent(parent[x]);
    }
    
    void Union(int x, int y){
        if(rank[x]<rank[y]){
            parent[x]=y;
        }else if(rank[x]>rank[y]){
            parent[y]=x;
        }else{
            parent[x]=y;
            rank[y]+=1;
        }
    }
};

class Solution {
  public:
    static bool compare(vector<int> &first, vector<int> &second){
        return first[2]<second[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end(),compare);
        int i=0,total=0;
        int edgesIncluded=0;
        while(i<edges.size()){
            int parentX = ds.findParent(edges[i][0]);
            int parentY = ds.findParent(edges[i][1]);
            int wt = edges[i][2];
            if(parentX!=parentY){
                ds.Union(parentX,parentY);
                edgesIncluded+=1;
                total+=wt;
                if(edgesIncluded==V-1) break;
            }
            i++;
        }
        return total;
    }
};