class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        if(n==1){
            return {0};
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }

        vector<int> ans;
        while(n>2){
            int len = q.size();
            n = n-len;
            while(len--){
                int neigh = q.front();
                q.pop();
                for(auto &it : adj[neigh]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }

        while(q.size()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
        }
        return ans;
    }
};