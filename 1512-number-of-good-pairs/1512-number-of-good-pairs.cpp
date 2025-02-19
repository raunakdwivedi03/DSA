class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int Number_of_Pairs=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    Number_of_Pairs++;
                }
            }

        }
        return Number_of_Pairs;
    }
};