class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int half = k / 2;

        long long originalProfit = 0;
        for (int i = 0; i < n; i++) {
            originalProfit += 1LL * strategy[i] * prices[i];
        }

        // delta arrays
        vector<long long> deltaHold(n), deltaSell(n);
        for (int i = 0; i < n; i++) {
            deltaHold[i] = -1LL * strategy[i] * prices[i];
            deltaSell[i] = 1LL * (1 - strategy[i]) * prices[i];
        }

        long long bestGain = 0;

        long long holdSum = 0, sellSum = 0;

        // initial window
        for (int i = 0; i < half; i++) holdSum += deltaHold[i];
        for (int i = half; i < k; i++) sellSum += deltaSell[i];

        bestGain = max(bestGain, holdSum + sellSum);

        // slide window
        for (int l = 1; l + k <= n; l++) {
            // update hold part
            holdSum -= deltaHold[l - 1];
            holdSum += deltaHold[l + half - 1];

            // update sell part
            sellSum -= deltaSell[l + half - 1];
            sellSum += deltaSell[l + k - 1];

            bestGain = max(bestGain, holdSum + sellSum);
        }

        return originalProfit + bestGain;
    }
};
