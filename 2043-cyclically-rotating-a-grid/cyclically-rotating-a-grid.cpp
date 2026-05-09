class Solution {
  public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int layer = 0; layer < min(m, n) / 2; ++layer) {
            int top = layer;
            int left = layer;
            int bottom = m - 1 - layer;
            int right = n - 1 - layer;

            int perimeter = 2 * (bottom - top + 1) + 2 * (right - left + 1) - 4;
            if (perimeter <= 0)
                continue;

            int rotations = k % perimeter;

            for (int rot = 0; rot < rotations; ++rot) {
                int temp = grid[top][left];

                for (int c = left; c < right; ++c) {
                    grid[top][c] = grid[top][c + 1];
                }

                for (int r = top; r < bottom; ++r) {
                    grid[r][right] = grid[r + 1][right];
                }

                for (int c = right; c > left; --c) {
                    grid[bottom][c] = grid[bottom][c - 1];
                }

                for (int r = bottom; r > top + 1; --r) {
                    grid[r][left] = grid[r - 1][left];
                }

                grid[top + 1][left] = temp;
            }
        }

        return grid;
    }
};