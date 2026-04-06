class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) return steps;

                vector<int>& nextNodes = graph[arr[curr]];
                nextNodes.push_back(curr - 1);
                nextNodes.push_back(curr + 1);

                for (int next : nextNodes) {
                    if (next >= 0 && next < n && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                graph[arr[curr]].clear(); 
            }
            steps++;
        }
        return -1;
    }
};