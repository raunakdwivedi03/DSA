class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int minStockPrice=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            minStockPrice=min(minStockPrice,prices[i]);
        
        int FinalProfit = prices[i]-minStockPrice;

        profit=max(FinalProfit,profit);
        }
        return profit;
    }
};