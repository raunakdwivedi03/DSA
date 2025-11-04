class Solution {
public:
      typedef pair<int,int>P;
    int findTopXsum(unordered_map<int,int>&map , int x){
        priority_queue<P,vector<P>, greater<P>>pq;

        for(auto &it :map){
            pq.push({it.second,it.first});

            if(pq.size() > x){
                pq.pop();
            }
        }
        int sum=0;
        while(!pq.empty()){
            auto[freq,val]=pq.top();
            pq.pop();

            sum +=freq*val;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
       int n=nums.size();
        unordered_map<int,int>map;

        vector<int>result;

        int i=0;
        int j=0;
        while(j<n){
            map[nums[j]]++;

            if(j-i+1 == k){
                result.push_back(findTopXsum(map,x));

                map[nums[i]]--;
                if(map[nums[i]] == 0){
                    map.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
        
    }
};