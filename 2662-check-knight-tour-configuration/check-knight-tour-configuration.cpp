class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &grid,int count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=count) return ;
        grid[i][j]=-1;
        dfs(i-2,j-1,grid,count+1);
        dfs(i-1,j-2,grid,count+1);
        dfs(i-2,j+1,grid,count+1);
        dfs(i-1,j+2,grid,count+1);
        dfs(i+2,j+1,grid,count+1);
        dfs(i+1,j+2,grid,count+1);
        dfs(i+2,j-1,grid,count+1);
        dfs(i+1,j-2,grid,count+1);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int count=0;
        dfs(0,0,grid,count); 
        for(auto &a:grid)
            for(auto &i:a)
                if(i!=-1) return false;
        return true;
    }
};