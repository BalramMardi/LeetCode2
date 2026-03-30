class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) {
                indegree[edges[i]]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> visited(n, false);
        while(q.size()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            
            int v = edges[u];
            if(v != -1) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        int max_len = -1;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int curr = i;
                int count = 0;
                
                while(!visited[curr]) {
                    visited[curr] = true;
                    curr = edges[curr];
                    count++;
                }
                
                max_len = max(max_len, count);
            }
        }

        return max_len;
    }
};