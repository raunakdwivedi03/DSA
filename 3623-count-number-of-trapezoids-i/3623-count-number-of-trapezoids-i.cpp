class Solution {
public:
    int M=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>map;

        for(auto &point : points){
            int y= point[1];
            map[y]++;
        }
        long long result=0;
        long long prevHoriLine=0;

        for(auto &it : map){
            int count=it.second;

            long long horiLines= (long long)count * (count -1)/2;

            result += horiLines*prevHoriLine;

            prevHoriLine += horiLines;
        }
        return result % M;
    }
};