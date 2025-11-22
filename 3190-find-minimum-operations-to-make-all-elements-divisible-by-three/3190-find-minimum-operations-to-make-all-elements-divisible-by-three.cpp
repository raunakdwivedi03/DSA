class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operation=0;

        for(int i : nums){
            if(i%3 != 0){
                operation++;
            }
        }
        return operation;
    }
};