class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int Parent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = Parent(parent[node]);
    }

    void Union(int u, int v)
    {
        int ulp_u = Parent(u);
        int ulp_v = Parent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        
        vector<pair<int, int>> temp(n);
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        vector<int> ans(n);

        DisjointSet ds(n);

        for (int i = 0; i < nums.size(); i++)
            temp[i] = {nums[i], i};

        sort(temp.begin(), temp.end());

        for (int i = 1; i < n; i++){
            if (temp[i - 1].first + limit >= temp[i].first)
                ds.Union(temp[i - 1].second, temp[i].second);
        }

        for (int i = 0; i < n; i++){
            int parent = ds.Parent(temp[i].second);
            mp[parent].push(temp[i].first);
        }

        for (int i = 0; i < n; i++){
            int parent = ds.Parent(i);
            ans[i] = mp[parent].top();
            mp[parent].pop();
        }

        return ans;
    }
};