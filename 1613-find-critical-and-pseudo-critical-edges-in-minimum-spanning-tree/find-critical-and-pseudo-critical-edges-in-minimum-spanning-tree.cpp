class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] > rank[yr]) parent[yr] = xr;
        else if (rank[xr] < rank[yr]) parent[xr] = yr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

class Solution {
public:
    int kruskalMST(int n, vector<vector<int>>& edges, int blockEdge, int includeEdge) {
        DSU dsu(n);
        int weight = 0, edgesUsed = 0;
        
        // Include a specific edge first
        if (includeEdge != -1) {
            dsu.unite(edges[includeEdge][0], edges[includeEdge][1]);
            weight += edges[includeEdge][2];
            edgesUsed++;
        }
        
        for (int i = 0; i < edges.size(); i++) {
            if (i == blockEdge) continue; // Skip this edge
            
            if (dsu.unite(edges[i][0], edges[i][1])) {
                weight += edges[i][2];
                edgesUsed++;
            }
        }
        return (edgesUsed == n - 1) ? weight : INT_MAX;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> indexedEdges;
        
        for (int i = 0; i < m; i++) {
            indexedEdges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }
        
        sort(indexedEdges.begin(), indexedEdges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        vector<vector<int>> edgesSorted(m);
        for (int i = 0; i < m; i++) {
            edgesSorted[i] = indexedEdges[i];
        }

        int minMSTWeight = kruskalMST(n, edgesSorted, -1, -1);
        vector<int> critical, pseudoCritical;
        
        for (int i = 0; i < m; i++) {
            int idx = edgesSorted[i][3];
            
            // Check if it's a critical edge
            if (kruskalMST(n, edgesSorted, i, -1) > minMSTWeight) {
                critical.push_back(idx);
            } 
            // Check if it's a pseudo-critical edge
            else if (kruskalMST(n, edgesSorted, -1, i) == minMSTWeight) {
                pseudoCritical.push_back(idx);
            }
        }
        
        return {critical, pseudoCritical};
    }
};
