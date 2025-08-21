class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
      int n=temperatures.size();
      vector<int>answer(n,0);
       for(int i=0;i<n;i++){
        while(!st.empty() && temperatures[i] >temperatures[st.top()]){
            int prevIndex=st.top();
            st.pop();
            answer[prevIndex]=i-prevIndex;
        }
        st.push(i);
       }
       return answer;
    }
};