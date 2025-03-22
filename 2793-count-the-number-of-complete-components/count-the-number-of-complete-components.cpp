class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;  

        UnionFind(int n) : parent(n, -1), size(n, 1) {}

        
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        void unionSets(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;
            }

            
            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        unordered_map<int, int> edgeCount;

        for (const auto& edge : edges) {
            dsu.unionSets(edge[0], edge[1]);
        }

        for (const auto& edge : edges) {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }

        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            if (dsu.find(vertex) == vertex) {  
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

};

/* class Solution {
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
 */