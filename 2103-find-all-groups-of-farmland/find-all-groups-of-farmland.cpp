class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;

        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != 1) continue;   

                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = 0;

                int rmin = i, rmax = i, cmin = j, cmax = j;

                while (!q.empty()) {
                    auto [row, col] = q.front(); q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nr = row + dir[d][0];
                        int nc = col + dir[d][1];

                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                            q.push({nr, nc});
                            grid[nr][nc] = 0;

                            rmin = min(rmin, nr);
                            rmax = max(rmax, nr);
                            cmin = min(cmin, nc);
                            cmax = max(cmax, nc);
                        }
                    }
                }

                ans.push_back({rmin, cmin, rmax, cmax});  
            }
        }

        return ans;
    }
};

/* class Solution {
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
}; */