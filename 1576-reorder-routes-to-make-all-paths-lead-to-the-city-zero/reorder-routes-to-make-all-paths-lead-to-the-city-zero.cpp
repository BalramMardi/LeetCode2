class Solution {
public:

    void dfs(vector<vector<pair<int,int>>>&graph,vector<bool>&vis,int &reorder,int node){
        vis[node]=true;
        for(auto it:graph[node]){
            if(!vis[it.first]){
                reorder+=it.second;
                dfs(graph,vis,reorder,it.first);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>> graph(n);
        vector<bool> vis(n,false);
        int reorder=0;
        for(auto it: connections){
            graph[it[0]].push_back({it[1],1});
            graph[it[1]].push_back({it[0],0});
        }


        dfs(graph,vis,reorder,0);

        return reorder;
    }
};