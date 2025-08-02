class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int first=0;
        int last=n-1;

        while(first<last){
            if(nums[first] > nums[last]){
                swap(nums[first],nums[last]); 
                last--;              
                }
                else if(first==last){
                    break;
                }      
                else{
                    first++;
                }
            }
            return ;
        }
    
};