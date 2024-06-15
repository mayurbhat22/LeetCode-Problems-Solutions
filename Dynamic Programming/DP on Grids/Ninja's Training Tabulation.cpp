#include <vector>
#include <algorithm> 

using namespace std;
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3, 0)); 
        
        for(int j=0; j<=2; j++)
        dp[0][j] = points[0][j];
        
        for(int i=1; i<=n-1; i++){
            for(int j=0; j<=2; j++){
                int maxPoints = 0;
                for (int ind = 0; ind <= 2; ind++) {
                    if (j != ind) {
                        int meritPoints = points[i][j] + dp[i - 1][ind];
                        maxPoints = max(maxPoints, meritPoints);
                    }
                }
                dp[i][j] = maxPoints;
            }
        }
        return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }
};

