class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--){
            for(int buy=1; buy>=0; buy--){
                int profit = 0;
                if(buy == 0){
                    int op1 = 0 + dp[i+1][0];
                    int op2 = -prices[i] + dp[i+1][1];
                    profit = max(op1, op2);
                }
                else if(buy == 1){
                    int op1 = 0 + dp[i+1][1];
                    int op2 = prices[i] + dp[i+1][0];
                    profit = max(op1, op2);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
};