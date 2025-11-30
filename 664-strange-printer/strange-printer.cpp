class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;

        string unique_s = "";
        for (char c : s) {
            if (unique_s.empty() || unique_s.back() != c) {
                unique_s += c;
            }
        }
        
        int n = unique_s.length();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                dp[i][j] = 1 + dp[i + 1][j];

                for (int k = i + 1; k <= j; k++) {
                    if (unique_s[k] == unique_s[i]) {
                        int turns = dp[i][k - 1] + (k + 1 <= j ? dp[k + 1][j] : 0);
                        dp[i][j] = min(dp[i][j], turns);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};