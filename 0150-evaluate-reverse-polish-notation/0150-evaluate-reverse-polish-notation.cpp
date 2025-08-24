// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         int n=tokens.size();
//         stack<int>st;

// for(int i=0;i<n;i++){
// if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
               
//      st.push(stoi(tokens[i]));
//           }
//             else if(tokens[i] == "+"){
//                 int top1=st.top();st.pop();
//                 int top2=st.top();st.pop();
//                 int result=top1+top2;  
//                 st.push(result);            
//             }
//               else if(tokens[i] == "-"){
//                 int top1=st.top();st.pop();
//                 int top2=st.top();st.pop();
//                 int result=top1-top2;  
//                 st.push(result);              
//             }
//               else if(tokens[i] == "*"){
//                 int top1=st.top();st.pop();
//                 int top2=st.top();st.pop();
//                 int result=top1*top2;   
//                 st.push(result);             
//             }
//               else if(tokens[i] == "/"){
//                 int top1=st.top();st.pop();
//                 int top2=st.top();st.pop();
//                 int result=abs(top2/top1);  
//                 st.push(result);              
//             }
// }

//             int ans =st.top();
//             st.pop();
        
//         return ans;
//     }
// };
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;   // \U0001f539 You forgot this

        for (int i = 0; i < n; i++) {
            // \U0001f539 tokens[i] is a string (not char), so we check operator or number
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i])); // \U0001f539 convert string number to int
            }
            else if (tokens[i] == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                int result = top2 + top1;   // \U0001f539 order corrected
                st.push(result);
            }
            else if (tokens[i] == "-") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                int result = top2 - top1;   // \U0001f539 order corrected
                st.push(result);
            }
            else if (tokens[i] == "*") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                int result = top2 * top1;   // \U0001f539 order corrected
                st.push(result);
            }
            else if (tokens[i] == "/") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                int result = top2 / top1;   // \U0001f539 order corrected
                st.push(result);
            }
        }

        int ans = st.top();  // \U0001f539 take final answer after loop
        st.pop();
        return ans;
    }
};
