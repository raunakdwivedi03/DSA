class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
          int n=nums.size();
        unordered_set<int>duplicate;

       for(int i=0;i<n;i++){
        if(duplicate.find(nums[i])!=duplicate.end()){
             return true;
        }
         duplicate.insert(nums[i]);
       }
      
        return false;
     
    }

};