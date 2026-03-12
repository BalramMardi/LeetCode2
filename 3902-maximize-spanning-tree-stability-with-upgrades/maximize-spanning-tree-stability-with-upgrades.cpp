class Solution {
    struct DSU {
        vector<int> parent, rank;
        int components;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
            components = n;
        }
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (rank[root_i] < rank[root_j]) {
                    parent[root_i] = root_j;
                } else if (rank[root_i] > rank[root_j]) {
                    parent[root_j] = root_i;
                } else {
                    parent[root_j] = root_i;
                    rank[root_i]++;
                }
                components--;
                return true;
            }
            return false;
        }
    };

    bool check(long long mid, int n, const vector<array<int, 3>>& must_edges, const vector<array<int, 3>>& opt_edges, int k) {
        DSU dsu(n);
        int edges_added = 0;
        
        for (const auto& e : must_edges) {
            if (e[2] < mid) return false;
            dsu.unite(e[0], e[1]);
            edges_added++;
        }
        
        for (const auto& e : opt_edges) {
            if (e[2] >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    edges_added++;
                }
            }
        }
        
        if (edges_added == n - 1) return true;
        
        int upgrades = 0;
        for (const auto& e : opt_edges) {
            if (e[2] < mid && (long long)e[2] * 2 >= mid) {
                if (dsu.unite(e[0], e[1])) {
                    edges_added++;
                    upgrades++;
                    if (edges_added == n - 1) {
                        return upgrades <= k;
                    }
                }
            }
        }
        
        return false;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU check_dsu(n);
        vector<array<int, 3>> must_edges;
        vector<array<int, 3>> opt_edges;
        
        long long high = 0;
        long long min_must = LLONG_MAX;
        
        for (const auto& e : edges) {
            high = max(high, (long long)e[2] * 2);
            if (e[3] == 1) {
                if (!check_dsu.unite(e[0], e[1])) return -1;
                must_edges.push_back({e[0], e[1], e[2]});
                min_must = min(min_must, (long long)e[2]);
            } else {
                opt_edges.push_back({e[0], e[1], e[2]});
            }
        }
        
        for (const auto& e : opt_edges) {
            check_dsu.unite(e[0], e[1]);
        }
        
        if (check_dsu.components > 1) return -1;
        
        high = min(high, min_must);
        long long low = 1, ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, n, must_edges, opt_edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};