class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Step 1: Push all 0s into the queue and mark distance = 0
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Step 2: BFS
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                // If inside bounds and we found a shorter distance
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
};
