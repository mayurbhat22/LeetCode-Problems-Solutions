#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(j>=matrix.size() || j<0) return INT_MAX;
        if(i==0) return matrix[i][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int path1 = f(i-1, j+1, matrix, dp);
        int path2 = f(i-1, j, matrix, dp);
        int path3 = f(i-1, j-1, matrix, dp);

        return dp[i][j] = min(path1, min(path2, path3)) + matrix[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        int minValue = INT_MAX;
        for(int j=n-1; j>=0; j--){
            minValue = min(minValue, f(m-1, j, matrix, dp));
        }
        return minValue;
    }
};