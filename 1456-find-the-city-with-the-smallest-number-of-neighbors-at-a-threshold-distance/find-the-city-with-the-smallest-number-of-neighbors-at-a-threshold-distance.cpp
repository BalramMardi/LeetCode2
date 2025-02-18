class Solution {
public:
    void floydWarshall(vector<vector<int>>& vec, int n) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (vec[i][k] < INT_MAX && vec[k][j] < INT_MAX) {
                        vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> vec(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) vec[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            vec[u][v] = w;
            vec[v][u] = w;
        }

        floydWarshall(vec, n);

        int minCity = -1, minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && vec[i][j] <= t) count++;
            }
            if (count <= minCount) {
                minCount = count;
                minCity = i;  
            }
        }

        return minCity;
    }
};
