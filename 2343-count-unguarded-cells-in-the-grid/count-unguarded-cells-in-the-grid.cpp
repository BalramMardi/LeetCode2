class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '0'));

        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (const auto& dir : directions) {
                int i = x, j = y;
                while (true) {
                    i += dir.first;
                    j += dir.second;
                    if (i < 0 || i >= m || j < 0 || j >= n ||
                        grid[i][j] == 'W' || grid[i][j] == 'G')
                        break;
                    if (grid[i][j] == '0')
                        grid[i][j] = 'X';
                }
            }
        }

        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};