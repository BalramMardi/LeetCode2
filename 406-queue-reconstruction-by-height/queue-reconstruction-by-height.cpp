class Solution {
public:
    vector<int> tree;

    void build(int node, int start, int end){
        if(start==end){
            tree[node]=1;
            return;
        }

        int mid = (start+end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];

    }

    void update(int node, int start, int end, int idx){
        if(start==end){
            tree[node]=0;
            return;
        }

        int mid = (start+end)/2;
        if(start <= idx && idx<=mid){
            update(2*node, start, mid,idx);
        }
        else{
            update(2*node+1,mid+1,end,idx);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }

    int query(int node, int start, int end, int k){
        if(start==end){
            return start;
        }

        int mid=(start+end)/2;
        if( tree[2*node] >= k){
            return query(2*node,start,mid,k);
        }
        else{
            return query(2*node+1,mid+1,end,k-tree[2*node]);
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        tree.resize(4*n);

        sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]) return a[1] > b[1];

            return a[0] < b[0];
        });

        build(1,0,n-1);
        vector<vector<int>> ans(n);
        for(auto &p:people ){
            int idx = query(1,0,n-1,p[1]+1);
            ans[idx]=p;
            update(1,0,n-1,idx);
        }

        return ans;
    }
};