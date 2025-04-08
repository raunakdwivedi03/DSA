class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Result(numRows);

     
          for(int i=0;i<numRows;i++){
             
       Result[i]=vector<int>(i+1,1);

       for(int j=1;j<i;j++){

              Result[i][j]=Result[i-1][j]+Result[i-1][j-1];       

       }


          }

          return Result;
    }
};