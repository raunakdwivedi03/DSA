class Solution {
public:
    void markGuard(int row,int col, vector<vector<int>>&result){
             for(int i=row-1;i>=0;i--){ // UP
                if(result[i][col] == 1 || result[i][col] == 2){
                    break;
                }
                result[i][col]=3;
             }
              for(int i=row+1;i<result.size();i++){ // down
                if(result[i][col] == 1 || result[i][col] == 2){
                    break;
                }
                result[i][col]=3;
             }
              for(int j=col-1;j>=0;j--){ //Left
                if(result[row][j] == 1 || result[row][j] == 2){
                    break;
                }
                result[row][j]=3;
             }
              for(int j=col+1;j<result[0].size();j++){ //right
                if(result[row][j] == 1 || result[row][j] == 2){
                    break;
                }
                result[row][j]=3;
             }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>result(m,vector<int>(n,0));

      for(vector<int>&vec : guards){
        int i=vec[0];
        int j=vec[1];
        result[i][j] =1;
      }
      for(vector<int>&vec : walls){
        int i = vec[0];
        int j = vec[1];
        result[i][j] =2;
      }

      for(vector<int>&guard : guards){
        int i=guard[0];
        int j=guard[1];
       markGuard(i,j,result);
      }
      
      int count=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(result[i][j] == 0){
                count++;
            }
        }
      }
        return count;
    }
};