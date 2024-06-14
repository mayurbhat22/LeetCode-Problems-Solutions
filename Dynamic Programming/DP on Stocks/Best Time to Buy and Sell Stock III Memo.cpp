#include <vector>
#include <algorithm> 

using namespace std;
class Solution {
public:
    int f(int i, int buy, int transactions, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(transactions == 2) return 0;
        if(i == prices.size()) return 0;
        if(dp[i][buy][transactions] != -1) return dp[i][buy][transactions];
        int profit = 0;
        if(buy == 0){
            int op1 = 0 + f(i+1, 0, transactions, prices, dp);
            int op2 = -prices[i] + f(i+1, 1, transactions, prices, dp);
            profit = max(op1, op2);
        }
        if(buy == 1){
            int op1 = 0 + f(i+1, 1, transactions, prices, dp);
            int op2 = prices[i] + f(i+1, 0, transactions+1, prices, dp);
            profit = max(op1, op2);
        }
        return dp[i][buy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 0, prices, dp);
    }
};