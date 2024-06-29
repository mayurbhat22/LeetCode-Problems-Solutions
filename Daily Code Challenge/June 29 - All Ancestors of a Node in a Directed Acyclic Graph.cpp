#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    void dfs(vector<int> adjList[], int ancestorNode, int node, vector<vector<int>> &ancestors, vector<bool> &vis){
        vis[node] = true;
        for(auto &adjNode : adjList[node]){
            if(!vis[adjNode]){
                ancestors[adjNode].push_back(ancestorNode);
                dfs(adjList, ancestorNode, adjNode, ancestors, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> ancestors(n);
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n);
            dfs(adjList, i, i, ancestors, vis);
         }
        return ancestors;
    }
};