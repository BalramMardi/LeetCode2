class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;
        int area = 1; // Start with the current cell

        // Explore all 4 directions
        area += dfs(grid, visited, i, j + 1);
        area += dfs(grid, visited, i + 1, j);
        area += dfs(grid, visited, i - 1, j);
        area += dfs(grid, visited, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int maxx = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = dfs(grid, visited, i, j);
                    if (area > maxx) {
                        maxx = area;
                    }
                }
            }
        }

        return maxx;
    }
};
