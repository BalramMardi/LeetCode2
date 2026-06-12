class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9+7;
    int LOG;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<vector<int>> up;

    void dfs(int node, int p){
        up[node][0]=p;

        for(int k=1;k<LOG;k++){
            up[node][k]=up[up[node][k-1]][k-1];
        }

        for(auto v : adj[node]){
            if(v!=p){
                depth[v]=depth[node]+1;
                dfs(v,node);
            }
        }

    }



    int kth(int k, int u){
        if (k > depth[u]) return -1;
        for(int i=0;i<LOG;i++){
            if(k & (1<<i)){
                u = up[u][i];
            }
        }

        return u;
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]){
            swap(u,v);
        }
        
        int diff=depth[u]-depth[v];
        u = kth(diff,u);

        if(u==v){
            return u;
        }

        for(int k=LOG-1;k>=0;k--){
            if(up[u][k]!=up[v][k]){
                u=up[u][k];
                v=up[v][k];
            }
        }

        return up[u][0];
    }

    ll binpow(ll a, ll b){
        ll res = 1;

        while(b){
            if(b&1){
                res = res*a%MOD;
            }
            a=a*a%MOD;
            b >>=1;
        }

        return res;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        int n = edges.size() + 1;

        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, vector<int>());
        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, 0));
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth[0] = 0;
        dfs(0,0);

        vector<int> ans;
        for(const auto& q:queries){
            int u = q[0];
            int v = q[1];
            u--,v--;
            int LCAncestor = lca(u,v);
            int L = depth[u]+depth[v]-2*depth[LCAncestor];

            if(L == 0){
                ans.push_back(0);
            } else {
                int val = binpow(2, L - 1) % MOD;
                ans.push_back(val);
            }
        }

        return ans;   
    }
};