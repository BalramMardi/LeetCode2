class Solution {
public:
    typedef pair<int, int> pp;

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> first(n + 1, INT_MAX), second(n + 1, INT_MAX);
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        first[1] = 0;
        pq.push({0, 1});  

        while (!pq.empty()) {
            auto [timePassed, node] = pq.top();
            pq.pop();

            if (node == n && second[n] != INT_MAX) {
                return second[n];
            }

        
            int mult = timePassed / change;
            if (mult % 2 == 1) {
                timePassed = change * (mult + 1);
            }

            for (int neigh : adj[node]) {
                int arrivalTime = timePassed + time;

                if (arrivalTime < first[neigh]) {
                    second[neigh] = first[neigh];
                    first[neigh] = arrivalTime;
                    pq.push({arrivalTime, neigh});
                } else if (arrivalTime > first[neigh] && arrivalTime < second[neigh]) {
                    second[neigh] = arrivalTime;
                    pq.push({arrivalTime, neigh});
                }
            }
        }

        return -1;
    }
};
