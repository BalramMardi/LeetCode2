class Solution {
public:
    struct State {
        int bx, by, px, py, moves;
    };

    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   
    bool isValid(int x, int y, int n, int m, vector<vector<char>>& grid) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#';
    }

    
    void computeReachable(vector<vector<char>>& grid,
                          vector<vector<bool>>& reachable, int px, int py,
                          int bx, int by) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({px, py});
        reachable[px][py] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (isValid(nx, ny, n, m, grid) && !reachable[nx][ny] &&
                    !(nx == bx && ny == by)) {
                    reachable[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int px, py, bx, by, tx, ty;

     
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S')
                    px = i, py = j;
                if (grid[i][j] == 'B')
                    bx = i, by = j;
                if (grid[i][j] == 'T')
                    tx = i, ty = j;
            }
        }

        queue<State> q;
        set<tuple<int, int, int, int>> visited;
        q.push({bx, by, px, py, 0});
        visited.insert({bx, by, px, py});

        while (!q.empty()) {
            auto [bx, by, px, py, moves] = q.front();
            q.pop();

     
            if (bx == tx && by == ty)
                return moves;

            vector<vector<bool>> reachable(n, vector<bool>(m, false));
            computeReachable(grid, reachable, px, py, bx, by);

            for (auto [dx, dy] : directions) {
                int newBx = bx + dx, newBy = by + dy;
                int newPx = bx - dx, newPy = by - dy;

                if (isValid(newBx, newBy, n, m, grid) &&
                    isValid(newPx, newPy, n, m, grid) &&
                    reachable[newPx][newPy]) {
                    if (visited.find({newBx, newBy, bx, by}) == visited.end()) {
                        visited.insert({newBx, newBy, bx, by});
                        q.push({newBx, newBy, bx, by, moves + 1});
                    }
                }
            }
        }

        return -1;
    }
};