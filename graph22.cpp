// Number Of Islands

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionbySize(int u, int v) {
        int x = findUpar(u);
        int y = findUpar(v);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        vector<int> ans;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto &it : operators) {
            int row = it[0];
            int col = it[1];

            // Already land → skip
            if (vis[row][col] == 1) {
                ans.push_back(count);
                continue;
            }

            vis[row][col] = 1;
            count++;

            int nodeNo = row * m + col;

            // Check 4 directions
            for (int i = 0; i < 4; i++) {
                int adjr = row + dr[i];
                int adjc = col + dc[i];

                if (isValid(adjr, adjc, n, m) && vis[adjr][adjc] == 1) {
                    int adjNodeNo = adjr * m + adjc;
                    if (ds.findUpar(nodeNo) != ds.findUpar(adjNodeNo)) {
                        count--;
                        ds.unionbySize(nodeNo, adjNodeNo);
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

