class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;
            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

/* class Solution {
public:
    typedef tuple<int,int,int> ti;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<ti, vector<ti>, greater<ti>> pq;

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()){
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(stops > k) continue;

            for(auto &[v, c] : adj[node]){
                if(cost + c < dist[v][stops+1]){
                    dist[v][stops+1] = cost + c;
                    pq.push({cost + c, v, stops+1});
                }
            }
        }

        return -1;
    }
}; */