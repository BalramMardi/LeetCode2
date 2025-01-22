class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=true;
                    ans[i][j]=0;
                }
            }
        }
        int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
        while(q.size()){
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int new_i = dir[i][0]+curr.first;
                int new_j = dir[i][1]+curr.second;
                if(new_i>=0 and new_i<n and new_j>=0 and new_j<m and !vis[new_i][new_j]){
                    q.push({new_i,new_j});
                    ans[new_i][new_j] = ans[curr.first][curr.second]+1;
                    vis[new_i][new_j] = true;
                }
            }
        }

        return ans;
    }
};