class Solution {
public:
    typedef pair<long long, int> pp;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        vector<vector<pp>> adj(n);

        for (auto& edge : roads) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long currDist = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (currDist > dist[curr]) continue;

            for (auto& neigh : adj[curr]) {
                int v = neigh.first;
                int wt = neigh.second;

                long long newDist = dist[curr] + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[curr];
                    pq.push({dist[v], v});
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[curr]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
