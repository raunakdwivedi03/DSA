class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        unordered_map<int,int>map;

        for(int i=0;i<n;i++){
            int remaining= target-nums[i];

            if(map.find(remaining) != map.end()){
                return {map[remaining],i};
            }

            map[nums[i]]=i;
        }
        return {};
    }
};