class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<double> prob(n, 0.0);
        priority_queue<pair<double,int>> pq;
        
        prob[start] = 1.0;
        pq.push({1.0, start});
        
        while(!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();
            
            if(u == end) return p;
            
            if(p < prob[u]) continue;
            
            for(auto &[v, w] : adj[u]) {
                if(prob[v] < prob[u] * w) {
                    prob[v] = prob[u] * w;
                    pq.push({prob[v], v});
                }
            }
        }
        
        return 0.0;
    }
};