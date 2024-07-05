class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Initialize indegree and outdegree arrays
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Populate the indegree and outdegree arrays
        for (auto& t : trust) {
            int u = t[0];
            int v = t[1];
            outdegree[u]++;
            indegree[v]++;
        }

        // Find the potential judge
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        // If no judge is found, return -1
        return -1;
    }
};
