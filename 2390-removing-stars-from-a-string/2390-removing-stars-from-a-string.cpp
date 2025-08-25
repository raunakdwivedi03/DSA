class Solution {
public:
    string removeStars(string s) {
        int n=s.size();

        stack<char>st;
        for(int i=0;i<n;i++){
            char ch=s[i];
             if(ch == '*'){
              st.pop();
             }
             else{
                st.push(ch);
             }            
        }
         string result="";
         while(!st.empty()){
            result.push_back(st.top());
            st.pop();
               
        }
        reverse(result.begin(),result.end());
        return result;
             
    }
};