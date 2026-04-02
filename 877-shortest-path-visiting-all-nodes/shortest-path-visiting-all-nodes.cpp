class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }

        int targetMask = (1 << n) - 1;

        while (!q.empty()) {
            auto [node, mask, dist] = q.front();
            q.pop();

            if (mask == targetMask) return dist;

            for (int neighbor : graph[node]) {
                int nextMask = mask | (1 << neighbor);
                if (!visited[neighbor][nextMask]) {
                    visited[neighbor][nextMask] = true;
                    q.push({neighbor, nextMask, dist + 1});
                }
            }
        }

        return -1;
    }
};