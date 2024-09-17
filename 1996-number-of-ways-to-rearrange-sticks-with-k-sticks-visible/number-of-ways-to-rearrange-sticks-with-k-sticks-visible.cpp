class Solution {
public:
    const int MOD = 1e9 + 7;

int rearrangeSticks(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
    // Base case
    dp[0][0] = 1; // One way to arrange 0 sticks with 0 visible
    
    // Fill dp array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + (long long)(i - 1) * dp[i - 1][j] % MOD) % MOD;
        }
    }
    
    return dp[n][k];
}

};