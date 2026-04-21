class Solution {
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
    
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        for (auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }
        
        unordered_map<int, unordered_map<int, int>> component_counts;
        for (int i = 0; i < n; ++i) {
            component_counts[find(i)][source[i]]++;
        }
        
        int distance = 0;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (component_counts[root][target[i]] > 0) {
                component_counts[root][target[i]]--;
            } else {
                distance++;
            }
        }
        
        return distance;
    }
};