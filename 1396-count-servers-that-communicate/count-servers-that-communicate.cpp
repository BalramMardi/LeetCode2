class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=size(grid);
        int m=size(grid[0]);

        vector<int> row(n,0);
        vector<int> col(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                   sum += row[i]>1 or col[j]>1 ;
                }
            }
        }
        
        return sum;



    }
};