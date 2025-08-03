class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int InitialSum=0;
        int MaxSum=nums[0];

        for(int i=0;i<=n-1;i++){
            InitialSum = InitialSum+nums[i];

           MaxSum=max(InitialSum,MaxSum);
           
           if(InitialSum <= 0)
            InitialSum = 0; 
        }     
       
    return MaxSum;
    }
};