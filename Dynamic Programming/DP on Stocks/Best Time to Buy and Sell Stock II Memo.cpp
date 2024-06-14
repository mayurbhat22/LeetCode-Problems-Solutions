class Solution {
public:
    int f(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == 0){
            int op1 = 0 + f(i+1, 0, prices, dp);
            int op2 = -prices[i] + f(i+1, 1, prices, dp);
            profit = max(op1, op2);
        }
        if(buy == 1){
            int op1 = 0 + f(i+1, 1, prices, dp);
            int op2 = prices[i] + f(i+1, 0, prices, dp);
            profit = max(op1, op2);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 0, prices, dp);
    }
};