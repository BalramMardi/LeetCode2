class Solution
{
public:
    long long MOD = 1e9 + 7;

    int countPermutations(vector<int> &complexity)
    {
        int n = complexity.size();

        if (n < 2)
            return 1;
        

        for (int i = 1; i < n; ++i)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }
        }

        long long ans = 1;

        for (int i = 1; i < n; ++i)
        {
            ans = (ans * i) % MOD;
        }

        return ans;
    }
};