class Solution {
public:
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                for (int mid = i; mid < j; ++mid) {
                    int leftSum = prefix[mid + 1] - prefix[i];
                    int rightSum = prefix[j + 1] - prefix[mid + 1];

                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][mid]);
                    } else if (rightSum < leftSum) {
                        dp[i][j] = max(dp[i][j], rightSum + dp[mid + 1][j]);
                    } else {
                        dp[i][j] = max(dp[i][j], leftSum + max(dp[i][mid], dp[mid + 1][j]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};