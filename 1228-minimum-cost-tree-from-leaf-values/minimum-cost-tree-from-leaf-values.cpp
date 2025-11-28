class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
         int n = arr.size();
        int dp[n][n];

        for (int i = 0; i < n; i++) dp[i][i] = 0;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {

                    int leftMax = 0;
                    for (int x = i; x <= k; x++)
                        leftMax = max(leftMax, arr[x]);

                    int rightMax = 0;
                    for (int x = k + 1; x <= j; x++)
                        rightMax = max(rightMax, arr[x]);

                    int cost = dp[i][k] + dp[k+1][j] + leftMax * rightMax;
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][n - 1];
    }
};