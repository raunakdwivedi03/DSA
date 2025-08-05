class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        sort(nums.begin(),nums.end());
         
   
     int i=0;
      while(i<n){
          int cnt=1;
            int j=i+1;
            while(j<n && nums[j]==nums[i] ){
                 cnt++;
                 j++;
            }
        if(cnt>n/3){
           result.push_back(nums[i]);
        }
        i=j;
      }
        return result;     
    }
};