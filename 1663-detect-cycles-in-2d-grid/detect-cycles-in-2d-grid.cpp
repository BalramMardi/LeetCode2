class Solution {
public:
    int n, m;

    bool dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited, int parentRow, int parentCol) {
      
        if (visited[row][col]) {
            return true; 
        }

        visited[row][col] = true;

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;

        
            if (newRow == parentRow && newCol == parentCol) {
                continue;
            }

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == grid[row][col]) {
                if (dfs(grid, newRow, newCol, visited, row, col)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, visited, -1, -1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
