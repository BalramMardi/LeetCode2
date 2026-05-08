class Solution {
public:

    vector<int> spf;

    vector<int> factorHelper(int num)
    {
        vector<int> factors;
        if (num <= 1)
            return factors;
        while (num != 1)
        {
            int p = spf[num];
            factors.push_back(p);
            while (num > 1 && num % p == 0)
            {
                num /= p;
            }
        }
        return factors;
    }
    
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
        {
            return 0;
        }

        int maxi = 0;

        for (int x : nums)
        {
            maxi = max(maxi, x);
        }

        spf.resize(maxi + 1);

        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= maxi; ++i)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= maxi; j += i)
                {
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        unordered_map<int, vector<int>> primemp;

        for (int i = 0; i < n; ++i)
        {
            vector<int> factors = factorHelper(nums[i]);
            for (int p : factors)
            {
                primemp[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        vector<bool> visited(maxi + 1, false);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == n - 1)
            {
                return dist[u];
            }

            int val = nums[u];

            if (val > 1 && spf[val] == val)
            {
                if (!visited[val])
                {
                    visited[val] = true;
                    if (primemp.count(val))
                    {
                        for (int v : primemp[val])
                        {
                            if (dist[v] == -1)
                            {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                            }
                        }
                    }
                }
            }

            if (u + 1 < n && dist[u + 1] == -1)
            {
                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }

            if (u - 1 >= 0 && dist[u - 1] == -1)
            {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }
        }

        return -1;
    }
};