class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }
        
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();
            
            if (u == n - 1) return d;
            
            if (d > dist[u][cur]) continue;
            
            for (auto& edge : g[u]) {
                int v = edge.first;
                int w = edge.second;
                
                int nxt = (labels[v] == labels[u]) ? cur + 1 : 1;
                int nd = d + w;
                
                if (nxt <= k && nd < dist[v][nxt]) {
                    dist[v][nxt] = nd;
                    pq.push({nd, v, nxt});
                }
            }
        }
        
        return -1;
    }
};