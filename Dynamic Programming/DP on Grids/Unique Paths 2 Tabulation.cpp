#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j] = 1;
                    continue;
                }
                int leftPath = 0, topPath = 0;
                if(j>0)
                    leftPath = dp[i][j-1];
                if(i>0)
                    topPath = dp[i-1][j];
                dp[i][j] = leftPath + topPath;
            }
        }
        return dp[m-1][n-1];
    }
};