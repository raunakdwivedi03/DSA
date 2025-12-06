class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<long long> dp(n + 1), ps(n + 1);
        dp[0] = ps[0] = 1;

        deque<int> mx, mn;

        int l = 0;

        for (int r = 0; r < n; r++) {
            // insert nums[r] into max deque
            while (!mx.empty() && mx.back() < nums[r]) mx.pop_back();
            mx.push_back(nums[r]);

            // insert nums[r] into min deque
            while (!mn.empty() && mn.back() > nums[r]) mn.pop_back();
            mn.push_back(nums[r]);

            // shrink window until valid
            while (!mx.empty() && !mn.empty() && mx.front() - mn.front() > k) {
                if (mx.front() == nums[l]) mx.pop_front();
                if (mn.front() == nums[l]) mn.pop_front();
                l++;
            }

            // dp[r+1] = sum(dp[l] ... dp[r])
            dp[r+1] = ps[r] - (l == 0 ? 0 : ps[l-1]);
            dp[r+1] = (dp[r+1] % MOD + MOD) % MOD;

            ps[r+1] = (ps[r] + dp[r+1]) % MOD;
        }

        return dp[n];
    }
};
