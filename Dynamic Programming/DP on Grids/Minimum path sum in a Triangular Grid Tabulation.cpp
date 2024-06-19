#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(triangle[m-1].size(), 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(i==0 && j==0){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int path1 = 100000;
                if(j<triangle[i-1].size())
                path1 = triangle[i][j] + dp[i-1][j];
                int path2 = 100000;
                if(j-1>=0)
                path2 = triangle[i][j] + dp[i-1][j-1];

                dp[i][j] = min(path1, path2);
            }
        }
        int minValue = 100000;
        for(int j=n-1; j>=0; j--){
            minValue = min(minValue, dp[m-1][j]);
        }
        return minValue;
    }
};
