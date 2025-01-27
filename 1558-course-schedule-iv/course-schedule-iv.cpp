class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre,
                                     vector<vector<int>>& queries) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<bool> ans;

        queue<int> queue;

        for (int i = 0; i < pre.size(); i++) {
            indegree[pre[i][1]]++;
            graph[pre[i][0]].push_back(pre[i][1]);
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        while (queue.size()) {
            int node = queue.front();
            queue.pop();
            for (auto& it : graph[node]) {
                visited[node][it] = true;
                for (int i = 0; i < n; i++) {
                    if (visited[i][node] == true) {
                        visited[i][it] = true;
                    }
                }
                indegree[it]--;
                if (indegree[it] == 0) {
                    queue.push(it);
                }
            }
        }

        for (int i = 0; i < queries.size(); i++)
            ans.push_back(visited[queries[i][0]][queries[i][1]]);
        return ans;
    }
};