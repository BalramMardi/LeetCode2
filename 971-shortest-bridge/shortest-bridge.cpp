

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        // Boundary check
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return;

        // Mark the cell as visited
        grid[i][j] = 2;
        q.push({i, j});

        // Explore the four directions
        dfs(grid, i + 1, j, q);
        dfs(grid, i - 1, j, q);
        dfs(grid, i, j + 1, q);
        dfs(grid, i, j - 1, q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool found = false;

        // Find the first island and mark it using DFS
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        // Directions for BFS
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 0;

        // BFS to expand the first island and find the shortest path to the second island
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                        if (grid[nx][ny] == 1) {
                            return steps;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }

        return -1; // In case no path is found (shouldn't happen with valid input)
    }
};

