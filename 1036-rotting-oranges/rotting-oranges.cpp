class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int minutes = -1;
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int sz = q.size();
            minutes++;              

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        if (fresh > 0) return -1;

        return minutes;
    }
};
