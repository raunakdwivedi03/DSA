class Solution {
public:
    int DivisorSum(vector<int>&nums,int k){
      int n=nums.size();
      int sum=0;

      for(int i=0;i<n;i++){
        sum=sum+ceil((double)(nums[i])/(double)(k));
      }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int left=1;
        int right= *max_element(nums.begin(),nums.end());

        while(left<=right){
            int mid=left+(right-left)/2;

            if(DivisorSum(nums,mid)<=threshold){
             right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};