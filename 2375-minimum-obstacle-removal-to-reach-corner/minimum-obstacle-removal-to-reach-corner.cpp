class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int d = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (r == m - 1 && c == n - 1) {
                return d;
            }
            
            if (d > dist[r][c]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i];
                int nc = c + dirs[i+1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newDist = d + grid[nr][nc];
                    if (newDist < dist[nr][nc]) {
                        dist[nr][nc] = newDist;
                        pq.push({newDist, nr, nc});
                    }
                }
            }
        }
        
        return 0;
    }
};