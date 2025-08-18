class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        stack<string>st;

        string result="";

        for(int i=0;i<n;i++){
            if(s[i]!=' '){
             result+=s[i];
            }
            else if(!result.empty()){
                st.push(result);
                result="";
            }
        }
        if(!result.empty())
        st.push(result);

        result="" ;
        while(!st.empty()){
            result+=st.top();
            st.pop();
            if(!st.empty())
            result+=" ";
        }
        return result;
    }
};