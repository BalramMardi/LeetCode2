class Solution {
public:
    int memo[101][101]; 
    int dfs(vector<vector<int>>& grid,int row,int col){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=0){
            return 0;
        }

        if(row==grid.size()-1 and col==grid[0].size()-1){
            return 1;
        }

        if(memo[row][col] != -1){
            return memo[row][col];
        }

        int right = dfs(grid,row,col+1);
        int down = dfs(grid,row+1,col);

        return  memo[row][col]=right+down;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(memo,-1,sizeof(memo));
        return dfs(obstacleGrid,0,0);
    }
};