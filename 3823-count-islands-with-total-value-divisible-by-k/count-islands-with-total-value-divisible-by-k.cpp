class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int islandCnt = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    long long sum = 0; 
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    visited[r][c] = true;

                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();
                        
                        sum = (sum + grid[curr_r][curr_c]) % k;
                        
                        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                        for (auto dir : directions) {
                            int next_r = curr_r + dir.first;
                            int next_c = curr_c + dir.second;
                            
                            if (next_r >= 0 && next_r < rows && next_c >= 0 && next_c < cols) {
                                if (grid[next_r][next_c] > 0 && !visited[next_r][next_c]) {
                                    visited[next_r][next_c] = true;
                                    q.push({next_r, next_c});
                                }
                            }
                        }
                    }
                    
                    if (sum == 0) {
                        islandCnt++;
                    }
                }
            }
        }
        return islandCnt;
    }
};