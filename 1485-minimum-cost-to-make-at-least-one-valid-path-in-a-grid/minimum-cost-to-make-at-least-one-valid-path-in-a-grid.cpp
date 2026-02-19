class Solution {
public:
   
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        dist[0][0] = 0;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            pair<int, int> curr = dq.front();
            int r = curr.first;
            int c = curr.second;
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int weight = (grid[r][c] == i + 1) ? 0 : 1;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};