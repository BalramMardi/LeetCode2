class Solution {
public:
    int n, m;
    vector<vector<int>> res;
    int rmin, rmax, cmin, cmax;

    void dfs(vector<vector<int>>& land, vector<vector<bool>>& vis, int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || land[r][c] != 1)
            return;

        vis[r][c] = true;

        rmin = min(rmin, r);
        rmax = max(rmax, r);
        cmin = min(cmin, c);
        cmax = max(cmax, c);

        dfs(land, vis, r+1, c);
        dfs(land, vis, r-1, c);
        dfs(land, vis, r, c+1);
        dfs(land, vis, r, c-1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    rmin = rmax = i;
                    cmin = cmax = j;

                    dfs(land, vis, i, j);

                    res.push_back({rmin, cmin, rmax, cmax});
                }
            }
        }

        return res;
    }
};