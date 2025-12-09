class Solution {
public:
    int M= 1e9+7;
    int specialTriplets(vector<int>& nums) {
       unordered_map<int,int>Valid_i;
       unordered_map<int,int>Valid_j;
           
           int result=0;
       for(int &num : nums){
        if(num%2 == 0){
            result=(result+Valid_j[num/2])%M;
        }

        Valid_j[num]=(Valid_j[num] + Valid_i[num*2]) % M;

        Valid_i[num]++;
       }

        return result;
    }
};