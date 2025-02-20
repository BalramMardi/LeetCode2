class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> answer(n);

        for (auto& pair : richer) {
            int rich = pair[0], poor = pair[1];
            graph[rich].push_back(poor);
            indegree[poor]++;
        }

        for (int i = 0; i < n; i++) {
            answer[i] = i;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);  
            }
        }

        while (!q.empty()) {
            int person = q.front();
            q.pop();

            for (int neighbor : graph[person]) {
                if (quiet[answer[person]] < quiet[answer[neighbor]]) {
                    answer[neighbor] = answer[person];
                }

                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return answer;
    }
};
