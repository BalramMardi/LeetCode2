
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < n; ++i)
                pre[j][i + 1] = pre[j][i] + grid[i][j];

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, 0));
            for (int c = 0; c <= n; ++c) {
                vector<long long> pref(n + 1, 0), suff(n + 2, 0);
                pref[0] = dp[c][0];
                for (int nxt = 1; nxt <= n; ++nxt) 
                    pref[nxt] = max(pref[nxt - 1], dp[c][nxt]);
                for (int nxt = n; nxt >= 0; --nxt)
                    suff[nxt] = max(suff[nxt + 1], (nxt > c ? pre[i][nxt] - pre[i][c] : 0) + dp[c][nxt]);
                
                for (int p = 0; p <= n; ++p) {
                    long long base = (p > c ? pre[i][p] - pre[i][c] : 0);
                    ndp[p][c] = (i == n - 1) ? base : max(base + pref[p], suff[p + 1]);
                }
            }
            dp = move(ndp);
        }
        
        long long ans = 0;
        for (int c = 0; c <= n; ++c) ans = max(ans, dp[0][c]);
        return ans;
    }
};