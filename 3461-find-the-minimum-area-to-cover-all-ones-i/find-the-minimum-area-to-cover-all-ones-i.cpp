class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int Imin = n, Imax = 0;
        int Jmin = m, Jmax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    Imin = min(Imin, i);
                    Imax = max(Imax, i);
                    Jmin = min(Jmin, j);
                    Jmax = max(Jmax, j);
                }
            }
        }
        return (Imax - Imin + 1) * (Jmax - Jmin + 1);
    }
};