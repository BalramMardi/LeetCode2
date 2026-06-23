class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1000000007;
        r -= l;
        vector<int> dp(r + 1, 1);
        
        for (int i = 1; i < n; i++) {
            long long pre = 0, pre2;
            if (i % 2 == 1) {
                for (int v = 0; v <= r; v++) {
                    pre2 = (pre + dp[v]) % MOD;
                    dp[v] = pre;
                    pre = pre2;
                }
            } else {
                for (int v = r; v >= 0; v--) {
                    pre2 = (pre + dp[v]) % MOD;
                    dp[v] = pre;
                    pre = pre2;
                }
            }
        }
        
        long long res = 0;
        for (int v : dp) {
            res = (res + v) % MOD;
        }
        
        return (res * 2) % MOD;
    }
};