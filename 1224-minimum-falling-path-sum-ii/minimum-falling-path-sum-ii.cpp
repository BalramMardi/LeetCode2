class Solution {
public:
    int memo[201][201];
    int solve(vector<vector<int>>&grid,int row,int col){
        if(row == grid.size()-1){
            return grid[row][col];
        }
        
        if(memo[row][col]!=-1){
            return memo[row][col];
        }
        int ans=INT_MAX;
        for(int i=0;i<grid.size();i++){
            if(i!=col)
                ans=min(ans,solve(grid,row+1,i));
        }

        return memo[row][col]= grid[row][col]+ans;
    }


    int minFallingPathSum(vector<vector<int>>& grid) {

        memset(memo,-1,sizeof(memo));
        int res=INT_MAX;
        for(int i=0;i<grid.size();i++){
            res = min(res,solve(grid,0,i));
        }
        return res;
    }
};