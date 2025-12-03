class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();

        unordered_map<float,vector<float>>slopeIntercepts;    
        unordered_map<int,vector<float>>midPointMap;
        int result=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dx=x2-x1;
                int dy=y2-y1;

                float slope,intercept;

                if(x2==x1){
                    slope=1e9+7;
                    intercept=x1;
                }
                else{
                    slope=(float)(y2-y1)/(x2-x1);
                    intercept=(float)(y1*dx - x1*dy)/dx;
                }
                int midPointkey=(x1+x2)*10000 + (y1+y2);

                slopeIntercepts[slope].push_back(intercept);
                midPointMap[midPointkey].push_back(slope);
            }
        }
for(auto &it:slopeIntercepts){
    if(it.second.size() <= 1)
    continue;
    map<float,int>map;
    for(float intercept : it.second){
        map[intercept]++;
    }
    int prevHorizlines=0;
    for(auto &it:map){
        int count=it.second;
        result += count* prevHorizlines;
        prevHorizlines += count;
    }
}
for(auto &it : midPointMap){
    if(it.second.size()<=1)
    continue;
    map<float,int>map;
    for(float slope : it.second){
        map[slope]++;
    }
    int prevHorizlines=0;
    for(auto &it:map){
        int count=it.second;
        result -= count* prevHorizlines;
        prevHorizlines += count;
    }
}
return result;
    }
};