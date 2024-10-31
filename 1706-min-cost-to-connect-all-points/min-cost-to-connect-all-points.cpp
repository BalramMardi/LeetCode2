#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& points, vector<vector<pair<int,int>>>& adj) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        vector<bool> vis(adj.size(), false);

        int res = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int u = node.second;
            int wt = node.first;

            if (vis[u]) {
                continue;
            }
            res += wt;
            vis[u] = true;
            for (auto& it : adj[u]) {
                if (!vis[it.first]) {
                    pq.push({it.second, it.first});
                }
            }
        }
        return res;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        } 
        int ans = bfs(points, adj);
        return ans;
    }
};
