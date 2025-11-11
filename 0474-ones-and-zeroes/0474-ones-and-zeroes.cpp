class Solution {
public:
    int solve(vector<pair<int,int>>& count, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        // Base case
        if (i >= count.size() || (m == 0 && n == 0)) {
            return 0;
        }

        // If already computed
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        int take = 0;
        // Try taking current string if possible
        if (count[i].first <= m && count[i].second <= n) {
            take = 1 + solve(count, m - count[i].first, n - count[i].second, i + 1, dp);
        }

        // Skip the current string
        int skip = solve(count, m, n, i + 1, dp);

        // Store and return result
        return dp[i][m][n] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int,int>> count(N);

        // Count zeros and ones in each string
        for (int i = 0; i < N; i++) {
            int CountZeros = 0;
            int CountOnes = 0;

            for (const char& ch : strs[i]) {
                if (ch == '0') CountZeros++;
                else CountOnes++;
            }
            count[i] = {CountZeros, CountOnes};
        }

        // 3D DP: dp[index][m][n]
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(count, m, n, 0, dp);
    }
};
