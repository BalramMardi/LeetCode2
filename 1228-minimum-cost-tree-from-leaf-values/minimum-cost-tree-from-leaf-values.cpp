class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n];
        int maxVal[n][n];

        for (int i = 0; i < n; i++) {
            maxVal[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
            }
        }

        for (int i = 0; i < n; i++) dp[i][i] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + (maxVal[i][k] * maxVal[k + 1][j]);
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};