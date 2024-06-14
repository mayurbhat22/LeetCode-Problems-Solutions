#include <vector>
#include <algorithm> 

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        int cap = k;
        for(int i=n-1; i>=0; i--){
            for(int buy=1; buy>=0; buy--){
                for(int k=1; k<=cap; k++){
                    int profit = 0;
                    if(buy == 0){
                        int op1 = 0 + dp[i+1][0][k];
                        int op2 = -prices[i] + dp[i+1][1][k];
                        profit = max(op1, op2);
                    }
                    if(buy == 1){
                        int op1 = 0 + dp[i+1][1][k];
                        int op2 = prices[i] + dp[i+1][0][k-1];
                        profit = max(op1, op2);
                    }
                    dp[i][buy][k] = profit;
                }
            }
        }
        return dp[0][0][k];
    }
};