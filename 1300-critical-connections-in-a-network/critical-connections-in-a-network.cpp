class Solution {
public:
    void DFS(vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<int> &parent, int vertex, int &time, vector<vector<int>> &bridges)
    {
        visited[vertex] = true;
        disc[vertex] = low[vertex] = ++time;
        int child = 0;

        for (int i = 0; i < adj[vertex].size(); ++i)
        {
            int v = adj[vertex][i];

            if (!visited[v])
            {
                ++child;
                parent[v] = vertex;
                DFS(adj, disc, low, visited, parent, v, time, bridges);
                low[vertex] = min(low[vertex], low[v]);

                if (low[v] > disc[vertex])
                    bridges.push_back({vertex, v});
            }
            else if (v != parent[vertex])
            {
                low[vertex] = min(low[vertex], disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        vector<bool> visited(V, false);
        vector<vector<int>> bridges;
        int time = 0;

        vector<vector<int>> adj(V);
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
                DFS(adj, disc, low, visited, parent, i, time, bridges);
        }

        return bridges;
    }
};