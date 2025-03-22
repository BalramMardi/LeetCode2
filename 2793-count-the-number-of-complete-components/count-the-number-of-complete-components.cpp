class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); 
            }
            return parent[x];
        }

        void Union(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);
            if (parentX != parentY) {
                if (rank[parentX] > rank[parentY]) {
                    parent[parentY] = parentX;
                } else if (rank[parentX] < rank[parentY]) {
                    parent[parentX] = parentY;
                } else {
                    parent[parentX] = parentY;
                    rank[parentY]++;
                }
            }
        }
    };

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        vector<unordered_set<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            dsu.Union(u, v);
            adj[u].insert(v);
            adj[v].insert(u);
        }

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        int count = 0;
        for (auto& [parent, nodes] : components) {
            bool isComplete = true;
            int size = nodes.size();
            for (int node : nodes) {
                if (adj[node].size() != size - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) count++;
        }

        return count;
    }
};
