class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        int mini = INT_MAX;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);  
            vector<int> parent(n, -1);
            queue<int> q;

            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neigh : adj[node]) {
                    if (dist[neigh] == -1) {  
                        dist[neigh] = dist[node] + 1;
                        parent[neigh] = node;
                        q.push(neigh);
                    }
                   
                    else if (parent[node] != neigh) {
                       
                        mini = min(mini, dist[node] + dist[neigh] + 1);
                    }
                }
            }
        }

        return (mini == INT_MAX) ? -1 : mini;  
    }
};
