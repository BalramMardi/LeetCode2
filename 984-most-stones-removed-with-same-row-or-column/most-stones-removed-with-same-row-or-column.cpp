class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.assign(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);

            if (parentX != parentY) {
                if (rank[parentX] < rank[parentY]) {
                    parent[parentX] = parentY;
                } else if (rank[parentX] > rank[parentY]) {
                    parent[parentY] = parentX;
                } else {
                    parent[parentY] = parentX;
                    rank[parentX]++;
                }
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);

        unordered_map<int, int> rowMap, colMap;

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            if (rowMap.count(x)) {
                dsu.unite(i, rowMap[x]);
            } else {
                rowMap[x] = i;
            }

            if (colMap.count(y)) {
                dsu.unite(i, colMap[y]);
            } else {
                colMap[y] = i;
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                components++;
            }
        }

        return n - components;
    }
};
