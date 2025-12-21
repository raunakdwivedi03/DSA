class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();//rows
        int m=strs[0].size();//columns

        //ek vector bna lenge sorted jisme ans save krna hai. 
        vector<bool>sorted(n,false);
        int deletion=0;

        int row=0;
        int col=0;

        for(col=0;col<m;col++){
            bool needDelete=false;

            for(int i=0;i<n-1;i++){
            if(!sorted[i] && strs[i][col] > strs[i+1][col]){
                needDelete = true;
                break;
            }    
            }
            if(needDelete){
                deletion++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(!sorted[i] && strs[i][col] < strs[i+1][col]){
                    sorted[i]=true;
                }
            }
        }
          return deletion;

    }
};