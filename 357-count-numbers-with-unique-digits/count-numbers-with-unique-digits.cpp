class Solution {
public:

    int dp[11][1 << 10][2][2]; // pos, mask, tight, leading_zero

    int dfs(const string &num, int pos, int mask, bool tight, bool leading_zero) {
        if (pos == num.size()) return 1;

        if (dp[pos][mask][tight][leading_zero] != -1)
            return dp[pos][mask][tight][leading_zero];

        int limit = tight ? (num[pos] - '0') : 9;
        int res = 0;

        for (int d = 0; d <= limit; ++d) {
            bool new_tight = tight && (d == limit);
            bool new_leading_zero = leading_zero && (d == 0);

            if (new_leading_zero) {
                res += dfs(num, pos + 1, mask, new_tight, true);
            } else {
                if ((mask >> d) & 1) continue;
                res += dfs(num, pos + 1, mask | (1 << d), new_tight, false);
            }
        }

        return dp[pos][mask][tight][leading_zero] = res;
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        string upper = string(n, '9'); 
        memset(dp, -1, sizeof(dp));
        return dfs(upper, 0, 0, 1, 1);
    }
};