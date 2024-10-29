class Solution {
public:
    int n,m;
    bool dfs(vector<vector<int>>&grid,int row,int col){
        if(row<0 || row>=n || col<0 || col>=m){
            return false;
        }

        if(grid[row][col] == 1){
            return true;
        }

        grid[row][col]=1;

        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

        bool flag=true;
        for(int i=0;i<4;i++){
            int newrow = row + dir[i][0];
            int newcol = col + dir[i][1];
            flag = dfs(grid,newrow,newcol) && flag;
        }
        return flag;
    }



    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count += dfs(grid,i,j) ? 1 : 0;
                }
            }
        }

        return count;
    }
};