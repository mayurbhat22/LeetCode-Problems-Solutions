#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int count = 1;
        long long res = 0;
        vector<long> adj(n);
        for(auto road : roads){
            adj[road[0]]++;
            adj[road[1]]++;
        }
        sort(adj.begin(), adj.end());
        for(auto node: adj){
            res += node * (count++);
        }
        return res;
    }
};