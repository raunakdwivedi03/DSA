class Solution {
public:
    string minimizeResult(string expression) {
        int plusSign = expression.find('+');
        string left = expression.substr(0, plusSign);
        int n = left.size();

        string right = expression.substr(plusSign + 1);
        int m = right.size();

        int best = INT_MAX;
        string ans ="";

        for (int i = 0; i < n; i++) {           
            for (int j = 0; j < m; j++) {       

                int leftSide;
                if (i == 0) {
                leftSide = 1;
                } else {
                    leftSide = stoi(left.substr(0, i));
                }

                int inLeftSide = stoi(left.substr(i));
                int inRightSide = stoi(right.substr(0, j + 1));

                int rightSide;
                if (j == m - 1) {
                    rightSide = 1;
                } else {
                    rightSide = stoi(right.substr(j + 1));
                }

                int val = leftSide * (inLeftSide + inRightSide) * rightSide;

                if (val < best) {
                    best = val;
                    ans = left.substr(0, i) + "(" + left.substr(i) + "+" +
                          right.substr(0, j + 1) + ")" + right.substr(j + 1);
                }
            }
        }
        return ans;
    }
};
