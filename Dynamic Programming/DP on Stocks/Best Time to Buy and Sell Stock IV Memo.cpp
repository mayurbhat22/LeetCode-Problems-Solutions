#include <vector>
#include <algorithm> 

using namespace std;
class Solution {
public:
    int f(int i, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(k == 0) return 0;
        if(i == prices.size()) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int profit = 0;
        if(buy == 0){
            int op1 = 0 + f(i+1, 0, k, prices, dp);
            int op2 = -prices[i] + f(i+1, 1, k, prices, dp);
            profit = max(op1, op2);
        }
        if(buy == 1){
            int op1 = 0 + f(i+1, 1, k, prices, dp);
            int op2 = prices[i] + f(i+1, 0, k-1, prices, dp);
            profit = max(op1, op2);
        }
        return dp[i][buy][k] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 0, k, prices, dp);
    }
};