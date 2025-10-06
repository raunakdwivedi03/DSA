class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;

        // mark the board visited
        board[i][j] = '#';

        dfs(board, m, n, i+1, j); // down
        dfs(board, m, n, i-1, j); // up
        dfs(board, m, n, i, j+1); // right
        dfs(board, m, n, i, j-1); // left
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        // Step 1: traverse boundaries
        for(int i = 0; i < m; i++) {
            dfs(board, m, n, i, 0);     // left border
            dfs(board, m, n, i, n-1);   // right border
        }
        for(int j = 0; j < n; j++) {
            dfs(board, m, n, 0, j);     // top border
            dfs(board, m, n, m-1, j);   // bottom border
        }

        // Step 2: flip surrounded 'O' -> 'X', safe '#' -> 'O'
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
