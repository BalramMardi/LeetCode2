class DSU {
private:
    vector<int> parent;

public:

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        while (parent[u] != u) {
            parent[u] = parent[parent[u]]; 
            u = parent[u];
        }
        return u;
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            parent[root_v] = root_u; 
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candidate1, candidate2;
        vector<int> cycle_edge; 

        // First pass: Find nodes with two parents
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] != 0) {
                // Node v already has a parent
                candidate1 = {parent[v], v}; // First edge causing the issue
                candidate2 = {u, v}; // Current edge causing the issue
                break; // Stop after finding the first node with two parents
            }
            parent[v] = u;
        }

        // Second pass: Detect cycles using DSU
        DSU dsu(n); 
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!candidate2.empty() && u == candidate2[0] && v == candidate2[1]) {
                
                continue;
            }
            if (dsu.find(u) == dsu.find(v)) {
                // Cycle detected
                cycle_edge = {u, v};
                break;
            }
            dsu.unite(u, v);
        }

        // Determine which edge to return
        if (candidate2.empty()) {
            // No node has two parents, return the cycle edge
            return cycle_edge;
        } else if (cycle_edge.empty()) {
            // No cycle detected, return candidate2
            return candidate2;
        } else {
            // Both candidates exist, return candidate1
            return candidate1;
        }
    }
};