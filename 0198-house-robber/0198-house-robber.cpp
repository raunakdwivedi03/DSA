class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
        return nums[0];

        int prePrev=0;
        int prev=nums[0];

        for(int i=2;i<=n;i++){
            int skip=prev;
            int steal=nums[i-1]+prePrev;

            int temp=max(skip,steal);

            prePrev=prev;
            prev=temp;
        }
return prev;
    }
};