class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        long num = 0;
        char operation = '+';

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && !isspace(c)) || i == n - 1) {
                if (operation == '+') {
                    st.push(num);
                } else if (operation == '-') {
                    st.push(-num);
                } else if (operation == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                } else if (operation == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }
                operation = c;
                num = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
