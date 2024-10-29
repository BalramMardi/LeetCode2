class Solution {
public:
    int solve(vector<vector<pair<int, int>>>& adj, vector<bool>& vis, int node) {
        vis[node] = true;
        int mini = INT_MAX;

        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            mini = min(mini, w); // Compare the edge weight directly

            if (!vis[v]) {
                mini = min(mini, solve(adj, vis, v)); // Recursively find min in connected nodes
            }
        }

        return mini;
    }   

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<bool> vis(n + 1, false);

        return solve(adj, vis, 1); 
    }
};



