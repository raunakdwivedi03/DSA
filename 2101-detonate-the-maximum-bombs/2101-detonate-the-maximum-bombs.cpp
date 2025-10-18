class Solution {
public:
    // DFS function — yeh recursively sab connected bombs ko explore karega
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, int& count) {
        visited[node] = 1;
        count++; // ek bomb uda diya \U0001f601

        // ab jitne bombs is bomb ke range me hain, unhe bhi uda do
        for (int nei : graph[node]) {
            if (!visited[nei]) {
                dfs(nei, graph, visited, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        // Step 1️⃣: Graph banana
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue; // same bomb skip

                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                // Distance ka square (sqrt avoid karne ke liye)
                long long distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                long long rangeSq = r1 * r1;

                // agar bomb j, bomb i ke range me aata hai
                if (distSq <= rangeSq) {
                    graph[i].push_back(j); // i se j tak edge banao
                }
            }
        }

        // Step 2️⃣: Har bomb se DFS chalao aur count karo
        int maxBombs = 0;

        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            int count = 0;
            dfs(i, graph, visited, count);
            maxBombs = max(maxBombs, count);
        }

        return maxBombs;
    }
};