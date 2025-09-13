class Solution {
public:
int n,m;

    int MaximumPathSum(vector<vector<int>>&grid,int i, int j){
      
        if(i>=n || j>=m || i < 0 || j<0 || grid[i][j] == 0){
        return 0; 
        }

     int gold = grid[i][j];
     grid[i][j]=0;

     int up=MaximumPathSum(grid,i-1,j);
     int down=MaximumPathSum(grid,i+1,j);
     int left=MaximumPathSum(grid,i,j-1);
     int right=MaximumPathSum(grid,i,j+1);

    grid[i][j]=gold;

    int sum = gold + max({up, down, left , right});

    return sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int result;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]>0){
                result=max(result,MaximumPathSum(grid,i,j));
              }
            }
        }
        return result;
    }
};