class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001];

    int solve(int i, int k) {
        if (k == 0) return 1;
        if (i <= 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int res = solve(i - 1, k);

     
        for (int j = 0; j < i; ++j) {
            res = (res + solve(j, k - 1)) % MOD;
        }

        return dp[i][k] = res;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n - 1, k); 
    }
};
