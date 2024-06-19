#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int f(int i, int j,vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(j<0 || j>= triangle[i].size()) return 100000;

        if(i==0) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int path1 = triangle[i][j] + f(i+1, j, triangle, dp);
        int path2 = triangle[i][j] + f(i+1, j+1, triangle, dp);

        return dp[i][j] = min(path1, path2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(triangle[m-1].size(), -1));
        int minVal = 100000;
        for(int ind=n-1; ind>=0; ind--)
            minVal = min(minVal, f(m-1, ind, triangle, dp));
        return minVal;
    }
};