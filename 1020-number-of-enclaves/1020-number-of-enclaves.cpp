class Solution {
public:
   int row,col;
   void dfs(vector<vector<int>>&grid , int i, int j){
    if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 0){
        return ;
    }

    grid[i][j]=0;
    dfs(grid,i+1,j);
    dfs(grid,i+1,j);
   }
    int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        int count=0;
        // traverse the boundaries 
        for(int i=0;i<row;i++){
            if(grid[row][0] == '1')
            return 0;
        }

        for(int j=0;j<col;j++){
            if(grid)
        }
    }
};