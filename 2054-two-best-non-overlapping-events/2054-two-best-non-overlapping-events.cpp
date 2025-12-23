class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0, r = n - 1;
        int result = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if (count == 2 || i == -1 || i >= n) return 0;

        if (dp[i][count] != -1) return dp[i][count];

        int nextIndex = binarySearch(events, events[i][1]);

        int take = events[i][2] + solve(events, nextIndex, count + 1);
        int notTake = solve(events, i + 1, count);

        return dp[i][count] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());

        dp.assign(n, vector<int>(3, -1));

        return solve(events, 0, 0);
    }
};
