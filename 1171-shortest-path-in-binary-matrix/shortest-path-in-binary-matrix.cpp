class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& g, vector<vector<bool>>& vis) {
        return i >= 0 && i < n && j >= 0 && j < m && g[i][j] == 0 && !vis[i][j];
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if (g[0][0] != 0 || g[n - 1][n - 1] != 0) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        q.push({0, 0});
        vis[0][0] = true;
        int res = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                if (i == n - 1 && j == n - 1) return res;

                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (isValid(ni, nj, n, n, g, vis)) {
                        q.push({ni, nj});
                        vis[ni][nj] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
