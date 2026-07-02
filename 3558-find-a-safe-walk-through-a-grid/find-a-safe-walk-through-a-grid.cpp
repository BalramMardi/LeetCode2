class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        deque<pair<int, int>> dq;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        dist[0][0] = grid[0][0];
        if (grid[0][0] == 1) {
            dq.push_back({0, 0});
        } else {
            dq.push_front({0, 0});
        }
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                return health > dist[r][c];
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int cost = grid[nr][nc];
                    if (dist[r][c] + cost < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + cost;
                        if (cost == 1) {
                            dq.push_back({nr, nc});
                        } else {
                            dq.push_front({nr, nc});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};