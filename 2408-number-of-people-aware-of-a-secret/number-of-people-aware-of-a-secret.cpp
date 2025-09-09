class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long MOD = 1e9+7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        long long shareWindow = 0; 

        for (int day = 2; day <= n; ++day) {
            int addIdx = day - delay;
            if (addIdx >= 1) {
                shareWindow = (shareWindow + dp[addIdx]) % MOD;
            }

            int remIdx = day - forget;
            if (remIdx >= 1) {
                shareWindow = (shareWindow - dp[remIdx] + MOD) % MOD;
            }

            dp[day] = shareWindow;
        }

        long long ans = 0;
        for (int j = max(1, n - forget + 1); j <= n; ++j) {
            ans = (ans + dp[j]) % MOD;
        }

        return (int)ans;
    }
};