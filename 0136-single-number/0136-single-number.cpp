class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(); 
        int i=0;
    
       while(i<n){
        int count=0;
    for(int j=0;j<n;j++){
        if(nums[i]==nums[j]){
            count++;           
        }      
    } 
            if( count == 1){
                return nums[i];            
            } 
               i++; 
      }   
        return -1; 
    }
};