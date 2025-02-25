class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
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

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);

        // Union all the connected indices
        for (auto& p : pairs) {
            dsu.unite(p[0], p[1]);
        }

        // Group indices by their root parent
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        // Sort characters within each group and place them back
        string result = s;
        for (auto& group : groups) {
            vector<int>& indices = group.second;
            sort(indices.begin(), indices.end());

            string chars;
            for (int idx : indices) {
                chars.push_back(s[idx]);
            }

            // Sort characters
            sort(chars.begin(), chars.end());

            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = chars[i];
            }
        }

        return result;
    }
};
