class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int frst=0;
        int last=n-1;
        while(frst<last){
            int sum=numbers[frst]+numbers[last];

            if(sum==target){
                return {frst + 1,last +1};

            }
            else if(sum>target){
               last--;
            }
            else{
                 frst++;
            }           
        }
        return {};
    }
};