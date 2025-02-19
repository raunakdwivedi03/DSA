class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
     int n=nums.size();

     unordered_map<int,int>map;
     
     for(int i=0;i<n;i++){
        map[nums[i]]++;
     }
     int count=0;

     for(auto it: map){
     int Good_pair=it.second;
     
     count += ( Good_pair*( Good_pair -1))/2;
     }
     return count;
    }
};











    //     int n = nums.size();
    //     int Number_of_Pairs = 0;

    //     for (int i = 0; i < n; i++) {
    //         for (int j = i + 1; j < n; j++) {
    //             if (nums[i] == nums[j]) {
    //                 Number_of_Pairs++;
    //             }
    //         }
    //     }
    //     return Number_of_Pairs;
    // }
