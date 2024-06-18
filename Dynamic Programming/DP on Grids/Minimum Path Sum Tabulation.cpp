#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int leftPath = 100000;
                if(j-1>=0)
                    leftPath = grid[i][j] + dp[i][j-1];
                int topPath = 100000;
                if(i-1>=0)
                    topPath = grid[i][j] + dp[i-1][j];

                dp[i][j] = min(leftPath, topPath);                
            }
        }
        return dp[m-1][n-1];
    }
};