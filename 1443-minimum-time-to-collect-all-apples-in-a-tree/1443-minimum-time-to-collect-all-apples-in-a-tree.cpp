#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int totalTime = 0;

        for (int child : adj[node]) {
            if (child == parent) continue; // jahan se aaye the, wapas mat jao

            int timeFromChild = dfs(child, node, adj, hasApple);

            // agar child subtree me koi apple hai → us tak jaane aur wapas aane ke liye +2 sec
            if (timeFromChild > 0 || hasApple[child]) {
                totalTime += timeFromChild + 2;
            }
        }

        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        
        // step 1: graph banana
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // step 2: dfs call from root node 0
        return dfs(0, -1, adj, hasApple);
    }
};
