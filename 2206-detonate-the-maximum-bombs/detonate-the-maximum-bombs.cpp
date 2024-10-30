class Solution {
public:
    int n,m;

    bool canDet(vector<int>&A,vector<int>&B){
        int Ax=A[0];
        int Ay=A[1];
        int Bx=B[0];
        int By=B[1];

        double val = sqrt(pow(Ax-Bx,2)+pow(Ay-By,2));
    
        return val<=A[2];    
    }

    int dfs(int idx,vector<vector<int>>&graph,vector<bool>&vis){
        vis[idx]=true;
        int count=1;
        for(auto &neigh : graph[idx]){
            if(vis[neigh]==false){
                count += dfs(neigh,graph,vis);
            }
        }
        return count;
    }


    int maximumDetonation(vector<vector<int>>& bombs) {
        n=bombs.size();
        m=bombs[0].size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and canDet(bombs[i],bombs[j])){
                    graph[i].push_back(j);
                }
            }
        }
        int maxdet=0;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            maxdet = max(maxdet,dfs(i,graph,vis));
        }

        return maxdet;
    }
};