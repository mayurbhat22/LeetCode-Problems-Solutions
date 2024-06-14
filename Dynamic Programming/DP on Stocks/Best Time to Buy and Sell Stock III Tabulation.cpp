class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--){
            for(int buy=1; buy>=0; buy--){
                for(int transactions=1; transactions>=0; transactions--){
                    int profit = 0;
                    if(buy == 0){
                        int op1 = 0 + dp[i+1][0][transactions];
                        int op2 = -prices[i] + dp[i+1][1][transactions];
                        profit = max(op1, op2);
                    }
                    if(buy == 1){
                        int op1 = 0 + dp[i+1][1][transactions];
                        int op2 = prices[i] + dp[i+1][0][transactions+1];
                        profit = max(op1, op2);
                    }
                    dp[i][buy][transactions] = profit;
                }
            }
        }
        return dp[0][0][0];
    }
};