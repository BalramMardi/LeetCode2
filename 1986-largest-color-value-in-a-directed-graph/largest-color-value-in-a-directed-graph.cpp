class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> dp(n, vector<int>(26, 0));

       
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processed = 0, result = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            dp[node][colors[node] - 'a']++;
            result = max(result, dp[node][colors[node] - 'a']);

            for (int neighbor : graph[node]) {
                for (int i = 0; i < 26; i++) {
                    dp[neighbor][i] = max(dp[neighbor][i], dp[node][i]);
                }
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return processed == n ? result : -1;
    }
};