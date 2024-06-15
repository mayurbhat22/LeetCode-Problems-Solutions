#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
  public:
    int f(int i, int j, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if (i == 0) return points[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxPoints = 0;
        for (int ind = 0; ind <= 2; ind++) {
            if (j != ind) {
                int meritPoints = points[i][j] + f(i - 1, ind, points, dp);
                maxPoints = max(maxPoints, meritPoints);
            }
        }
        return dp[i][j] = maxPoints;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3, -1)); // Memoization table
        int result = INT_MIN;
        for (int j = 0; j < 3; j++) {
            result = max(result, f(n - 1, j, points, dp));
        }
        return result;
    }
};