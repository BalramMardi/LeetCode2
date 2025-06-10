class Solution {
public:
    int dp[1001];

    int solve(int n) {
        if (n == 1) return 0;
        if (dp[n] != -1) return dp[n];

        dp[n] = n; 
        for (int i = n - 1; i >= 1; i--) {
            if (n % i == 0) {
                dp[n] = min(dp[n], solve(i) + (n / i));
            }
        }
        return dp[n];
    }

    int minSteps(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
