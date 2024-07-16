class Solution {
public:
    int dp[100];

    int solve(int n) {
        if (n == 1) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int result = 0;

        for (int i = 1; i <= n - 1; ++i) {
            int prod = i * max(n - i, solve(n - i));
            result = max(prod, result);
        }

        return dp[n] = result;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
