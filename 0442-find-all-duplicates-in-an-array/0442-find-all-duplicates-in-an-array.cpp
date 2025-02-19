class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
          
          unordered_map<int,int>map;
          for(int i=0;i<n;i++){
            map[nums[i]]++;
          }

          vector<int>result;
          for(auto it: map){
            if(it.second>1){
                result.push_back(it.first);
            }
           
          }

          return result;
    }
};