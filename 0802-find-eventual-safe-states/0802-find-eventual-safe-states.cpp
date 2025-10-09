class Solution {
public:
    bool dfs(int node, vector<vector<int>>&graph , vector<int>& color){
        if(color[node] !=0){
            return color[node]==2;
        }
        color[node]=1;

        for(int neighbour :graph[node]){
            if(color[neighbour]==2) continue;
            if(color[neighbour]==1 || !dfs(neighbour,graph,color)){
                return false;
            }
        }
        color[node]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>color(n,0);
        vector<int>result;

        for(int i=0;i<n;i++){
            if(dfs(i,graph,color)){
                result.push_back(i);
            }
        }
        return result;        
    }
};