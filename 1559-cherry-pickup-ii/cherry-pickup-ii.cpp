class Solution {
public:
    int memo[71][71][71];
    int solve(vector<vector<int>>& grid,int row,int col1,int col2){
        
        if(row>=grid.size()){
            return 0;
        }

        if(memo[row][col1][col2]!=-1){
            return memo[row][col1][col2];
        }
        int cherry=grid[row][col1];
        if(col1!=col2){
            cherry += grid[row][col2];
        }

        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newrow = row+1;
                int newcol1 = col1+i;
                int newcol2 = col2+j;
                if (newcol1 >= 0 && newcol2 >= 0 && newcol1 < grid[0].size() && newcol2 < grid[0].size()) 
                    ans=max(ans,solve(grid,newrow,newcol1,newcol2)); 
            }
        }

        return memo[row][col1][col2]= cherry+ans;
    }



    int cherryPickup(vector<vector<int>>& grid) {
        memset(memo,-1,sizeof(memo));
        return solve(grid,0,0,grid[0].size()-1);
    }
};