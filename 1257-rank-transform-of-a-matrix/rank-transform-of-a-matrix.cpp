class Solution {
public:
    class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return {};
    int n = matrix[0].size();

    map<int, vector<pair<int, int>>> valueToPositions;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            valueToPositions[matrix[i][j]].emplace_back(i, j);
        }
    }

    vector<vector<int>> rank(m, vector<int>(n, 0));

    vector<int> maxRankInRow(m, 0);
    vector<int> maxRankInCol(n, 0);

    for (auto& [value, positions] : valueToPositions) {
        UnionFind uf(m + n);

        for (auto& [i, j] : positions) {
            uf.unite(i, m + j); 
        }

        map<int, int> groupMaxRank;

        for (auto& [i, j] : positions) {
            int root = uf.find(i);
            groupMaxRank[root] = max(groupMaxRank[root], max(maxRankInRow[i], maxRankInCol[j]));
        }

        for (auto& [i, j] : positions) {
            int root = uf.find(i);
            rank[i][j] = groupMaxRank[root] + 1;
            maxRankInRow[i] = rank[i][j];
            maxRankInCol[j] = rank[i][j];
        }
    }

    return rank;
}
};