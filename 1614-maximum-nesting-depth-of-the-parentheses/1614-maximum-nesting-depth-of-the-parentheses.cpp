class Solution {
public:
    int maxDepth(string s) {
       int DepthCount=0;
       int MaxDepth=0;
       int n=s.size();
       stack<char>st;

       for(int i=0;i<n;i++){
        if(s[i] == '('){
            st.push(s[i]);
            DepthCount++;
           MaxDepth=max(MaxDepth,DepthCount);
        }
        else if(s[i] == ')'){
            st.pop();
            DepthCount--;
        }
       }
       return MaxDepth;
    }
};