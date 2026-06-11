class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;

    vector<vector<int>> adj;
    vector<bool> vis;
    int dfs(int node){
        vis[node]=true;
        int depth=0;
        for(int it : adj[node]){
            if(vis[it]){continue;}
            depth = max(depth, 1 + dfs(it));
        }

        return depth;
    }

    ll binpow(ll a, ll b){

        ll res = 1;
        while(b){
            if(b&1){
                res=res*a%MOD;
            }
            a = a*a%MOD;
            b >>= 1;
        }

        return res;
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();

        adj.resize(n+1);
        vis.assign(n+1, false);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int depth=dfs(0);

        if (depth == 0) return 0;

        return binpow(2, depth - 1);
      
    }
};