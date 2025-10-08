class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
         queue<int>que;

        for(int i=0;i<n;i++){
        if(visited[i] ==-1){
           que.push(i);
           visited[i]=0;


           while(!que.empty()){
           int node=que.front();
            que.pop();

            for(int i=0;i<graph[node].size();i++){
                int neighbour =graph[node][i];

                if(visited[neighbour]==-1){
                    visited[neighbour]=1-visited[node];
                    que.push(neighbour);                   
                }
                else if(visited[neighbour]==visited[node]){
                    return false;
                }
            }
           }

        }
}  
return true;
  }
};