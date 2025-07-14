class Solution {
public:
    const int mod = 1e9 + 7;
    long long dp[23][2][401];

    long long helper(string &str, int idx, bool tight, int sum, int maxi, int mini) {
        if (idx == str.size())
            return (mini <= sum && sum <= maxi) ? 1 : 0;

        if (dp[idx][tight][sum] != -1)
            return dp[idx][tight][sum];

        int limit = tight ? str[idx] - '0' : 9;
        long long res = 0;

        for (int i = 0; i <= limit; i++) {
            bool newTight = tight && (i == limit);
            res = (res + helper(str, idx + 1, newTight, sum + i, maxi, mini)) % mod;
        }

        return dp[idx][tight][sum] = res;
    }

    int count(string num1, string num2, int mini, int maxi) {
        memset(dp, -1, sizeof(dp));
        long long right = helper(num2, 0, true, 0, maxi, mini);

        memset(dp, -1, sizeof(dp));
        long long left = helper(num1, 0, true, 0, maxi, mini);

        int sum = 0;
        for (char d : num1)
            sum += (d - '0');

        if (sum >= mini && sum <= maxi)
            left--;

        return ((right - left + mod) % mod);
    }
};
