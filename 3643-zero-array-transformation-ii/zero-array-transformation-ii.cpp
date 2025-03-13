class Solution {
public:
    
   bool isAllZero(const vector<int> &arr)
    {
        for (int it : arr)
        {
            if (it != 0)
            {
                return false;
            }
        }
        return true;
    }
    bool check(int k, vector<int> &curr, vector<vector<int>> &ops, int n)
    {
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < k; ++i)
        {
            int l = ops[i][0], r = ops[i][1], v = ops[i][2];
            diff[l] += v;
            if (r + 1 < n)
                diff[r + 1] -= v;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += diff[i];
            if (sum < curr[i])
                return false;
        }
        return true;
    }
    
    
    
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         int n = nums.size();
        vector<int> curr = nums;
        vector<int> result;
        if (isAllZero(curr))
        {
            result = curr;
            return 0;
        }

        int l = 0, r = queries.size();
        int ans = -1;
        bool stateSaved = false;

        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (check(m, curr, queries, n))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }

            if (!stateSaved && m == queries.size() / 2)
            {
                vector<int> diff(n + 1, 0);
                for (int i = 0; i < m; ++i)
                {
                    int l = queries[i][0], r = queries[i][1], v = queries[i][2];
                    diff[l] += v;
                    if (r + 1 < n)
                        diff[r + 1] -= v;
                }

                result = curr;
                int sum = 0;
                for (int i = 0; i < n; ++i)
                {
                    sum += diff[i];
                    result[i] = max(0, curr[i] - sum);
                }
                stateSaved = true;
            }
        }

        return ans != -1 ? ans : -1;
    }
};