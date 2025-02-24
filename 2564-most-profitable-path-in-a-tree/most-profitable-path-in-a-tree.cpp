class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bobPath;
    vector<bool> visited;
    int maxProfit;

    bool findBobPath(int node, int parent, int bob) {
        if (node == bob) {
            bobPath[node] = 0;
            return true;
        }

        for (int neigh : adj[node]) {
            if (neigh != parent && findBobPath(neigh, node, bob)) {
                bobPath[node] = bobPath[neigh] + 1;
                return true;
            }
        }
        return false;
    }

    void dfs(int node, int parent, int currDepth, int currProfit, vector<int>& amount) {
        if (currDepth < bobPath[node]) {
            currProfit += amount[node];
        } else if (currDepth == bobPath[node]) {
            currProfit += amount[node] / 2;
        }

        bool isLeaf = true;
        for (int neigh : adj[node]) {
            if (neigh != parent) {
                isLeaf = false;
                dfs(neigh, node, currDepth + 1, currProfit, amount);
            }
        }

        if (isLeaf) {
            maxProfit = max(maxProfit, currProfit);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        adj.resize(n);
        bobPath.assign(n, INT_MAX);
        visited.assign(n, false);
        maxProfit = INT_MIN;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        findBobPath(0, -1, bob);

        dfs(0, -1, 0, 0, amount);

        return maxProfit;
    }
};
