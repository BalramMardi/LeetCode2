class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int targetState = 0, startR = -1, startC = -1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    targetState |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        
        queue<vector<int>> q;
        q.push({startR, startC, 0, 0});
        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        vis[startR][startC][0] = true;
        
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int r = curr[0], c = curr[1], keys = curr[2], steps = curr[3];
            
            if (keys == targetState) return steps;
            
            for (auto& d : dir) {
                int nr = r + d[0], nc = c + d[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != '#') {
                    char ch = grid[nr][nc];
                    int nkeys = keys;
                    
                    if (ch >= 'a' && ch <= 'f') {
                        nkeys |= (1 << (ch - 'a'));
                    }
                    
                    if (ch >= 'A' && ch <= 'F' && !((nkeys >> (ch - 'A')) & 1)) {
                        continue;
                    }
                    
                    if (!vis[nr][nc][nkeys]) {
                        vis[nr][nc][nkeys] = true;
                        q.push({nr, nc, nkeys, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};