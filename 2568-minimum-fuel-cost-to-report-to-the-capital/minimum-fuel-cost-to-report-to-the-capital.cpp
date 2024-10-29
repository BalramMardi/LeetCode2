class Solution {
public:
    long long ans;

    long long solve(vector<vector<int>>& adj, int node, vector<bool>& vis, int seat) {
        vis[node] = true;
        long long count = 1;

        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                count += solve(adj, neigh, vis, seat); // Add subtree count
            }
        }

        long long val = count / seat;
        if (count % seat) val++;

        if (node != 0) {
            ans += val;
        }

        return count; 
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        if (n == 0) {
            return 0;
        }

        ans = 0;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n; i++) {
            int u = roads[i][0], v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        solve(adj, 0, vis, seats);
        return ans;
    }
};
