class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int servers = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    bool can_comm = false;
                    for(int r = 0; r < m; ++r) {
                        for(int c = 0; c < n; ++c) {
                            if(grid[r][c] == 1 && (r != i || c != j)) {
                                if(r == i || c == j) {
                                    can_comm = true;
                                }
                            }
                        }
                    }
                    if(can_comm) {
                        servers++;
                    }
                }
            }
        }
        
        return servers;
    }
};