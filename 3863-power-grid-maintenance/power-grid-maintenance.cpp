class Solution {
public:

    class DSU
    {
    public:
        vector<int> parent;
        vector<int> size;
    
        DSU(int n)
        {
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.assign(n + 1, 1);
        }
    
        int find(int i)
        {
            if (parent[i] == i)
            {
                return i;
            }
            return parent[i] = find(parent[i]);
        }
    
        void unite(int i, int j)
        {
            int rootX = find(i);
            int rootY = find(j);
            if (rootX != rootY)
            {
                if (size[rootX] < size[rootY])
                {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    };
    
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (const auto &it : connections)
        {
            dsu.unite(it[0], it[1]);
        }
    
        map<int, set<int>> grid;
    
        for (int i = 1; i <= c; ++i)
        {
            grid[dsu.find(i)].insert(i);
        }
    
        vector<int> res;
    
        vector<bool> onOp(c + 1, true);
    
        for (const auto &q : queries)
        {
            int code = q[0];
            int st = q[1];
    
            if (code == 1)
            {
                if (onOp[st])
                {
                    res.push_back(st);
                }
                else
                {
                    int root = dsu.find(st);
    
                    if (!grid[root].empty())
                        res.push_back(*grid[root].begin());
    
                    else
                        res.push_back(-1);
                }
            }
            else if (code == 2)
            {
                if (onOp[st])
                {
                    onOp[st] = false;
                    int root = dsu.find(st);
                    grid[root].erase(st);
                }
            }
        }
    
        return res;
    }
};