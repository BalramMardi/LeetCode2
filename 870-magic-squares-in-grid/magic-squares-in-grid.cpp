class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        vector<int> cnt(10, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = g[i][j];
                if (x < 1 || x > 9 || cnt[x]) return false;
                cnt[x]++;
            }
        }

        for (int i = 0; i < 3; i++) {
            int s = 0;
            for (int j = 0; j < 3; j++)
                s += g[r + i][c + j];
            if (s != 15) return false;
        }

        for (int j = 0; j < 3; j++) {
            int s = 0;
            for (int i = 0; i < 3; i++)
                s += g[r + i][c + j];
            if (s != 15) return false;
        }

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != 15) return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (isMagic(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};