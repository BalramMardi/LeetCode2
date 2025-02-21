

class Solution {
public:

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, int rows, int cols) {

    if (r < 0 || r >= rows || c < 0 || c >= cols || grid2[r][c] == 0) return true;


    grid2[r][c] = 0;

  
    bool isSubIsland = grid1[r][c] == 1;

 
    isSubIsland = dfs(grid1, grid2, r+1, c, rows, cols) & isSubIsland;
    isSubIsland = dfs(grid1, grid2, r-1, c, rows, cols) & isSubIsland;
    isSubIsland = dfs(grid1, grid2, r, c+1, rows, cols) & isSubIsland;
    isSubIsland = dfs(grid1, grid2, r, c-1, rows, cols) & isSubIsland;

    return isSubIsland;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size();
        int cols = grid2[0].size();
        int count = 0;

        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid2[r][c] == 1) {
                    if (dfs(grid1, grid2, r, c, rows, cols)) {
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
};



