class Solution {
public:
    int trapRainWater(vector<vector<int>>& arr) {
        int n= arr.size();
        int m= arr[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                    pq.push({arr[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }

        int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
        
        int water=0;
        while(pq.size()){
            auto top = pq.top();
            pq.pop();
            int height = top.first;
            int i=top.second.first;
            int j=top.second.second;

            for(auto it : dir){
                int new_i = i+it[0];
                int new_j = j+it[1];
                if(new_i >= 0 && new_i<n && new_j>=0 && new_j < m && !visited[new_i][new_j]){
                    visited[new_i][new_j]=true;
                    water += max(height - arr[new_i][new_j],0);
                    pq.push({max(height,arr[new_i][new_j]),{new_i,new_j}});
                }
            }
        }

        return water;
    }
};