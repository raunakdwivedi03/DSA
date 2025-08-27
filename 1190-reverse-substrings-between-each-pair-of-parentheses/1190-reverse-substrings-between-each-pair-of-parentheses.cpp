class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
         int n=s.size();
        string result ="";

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(ch == '('){
                st.push(result);
                result = "";
            }
            else if(ch == ')'){
                reverse(result.begin(),result.end());

                result=st.top() + result;
                st.pop();
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
};