#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class UnionFind {
public:
    int nodes;
    vector<int> par;
    vector<int> rank;

    UnionFind(int n) {
        nodes = n;
        par.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) { 
            par[i] = i;
        }
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    int union_sets(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);

        if (p1 == p2) {
            return 0;
        }

        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        } else if (rank[p1] < rank[p2]) {
            par[p1] = p2;
        } else {
            par[p2] = p1;
            rank[p1]++;
        }
        nodes--;
        return 1;
    }

    bool isConnected() {
        return nodes == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n);
        UnionFind bob(n);
        int cnt = 0;

        for (auto edge : edges) {
            if (edge[0] == 3) {
                if (alice.union_sets(edge[1], edge[2]) | bob.union_sets(edge[1], edge[2])) {
                    cnt++;
                }
            }
        }

        for (auto edge : edges) {
            if (edge[0] == 2) {
                cnt += bob.union_sets(edge[1], edge[2]);
            } else if (edge[0] == 1) {
                cnt += alice.union_sets(edge[1], edge[2]);
            }
        }

        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - cnt;
        }
        return -1;
    }
};

