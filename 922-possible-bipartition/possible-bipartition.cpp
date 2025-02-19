class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        vector<int> color(n, -1);
        for (int i = 0; i < dislikes.size(); i++) {
            int u = dislikes[i][0]-1;
            int v = dislikes[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {

                queue<int> q;
                q.push(i);

                color[i] = 0;

                while (q.size()) {
                    int node = q.front();
                    q.pop();

                    for (int neigh : adj[node]) {

                        if (color[neigh] == -1) {
                            color[neigh] = 1 - color[node];
                            q.push(neigh);
                        } else if (color[neigh] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};