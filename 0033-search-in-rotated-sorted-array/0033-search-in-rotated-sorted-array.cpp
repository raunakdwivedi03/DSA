class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        
        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target) return mid;

            if(nums[left]<=nums[mid]){
                if(nums[left]<= target && nums[mid]>=target){
                  right=mid-1;
                }
                    else{
                       left=mid+1;
                    }
                }
            
                     else if(nums[mid]>=nums[right]){
                       if(nums[mid]<=target && nums[right]>=target){
                        right=mid-1;
                       }
                       else
                       left=mid+1;
   }
                }
            
        return -1;
    }
};