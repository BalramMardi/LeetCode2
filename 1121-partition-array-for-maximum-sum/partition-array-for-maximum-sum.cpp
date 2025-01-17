class Solution {
public:
    int memo[501];
    int solve(vector<int>& arr, int i, int k) {
        if (i >= arr.size()) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        int result = 0;
        int currmax = -1;

        for (int j = i; j < arr.size() && j - i + 1 <= k; j++) {
            currmax = max(currmax, arr[j]);
            result = max(result, (j - i + 1) * currmax + solve(arr, j + 1, k));
        }

        return memo[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        // memset(memo,-1,sizeof(memo));
        // return solve(arr,0,k);

        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int maxVal = 0, maxSum = 0;

            for (int j = 0; j < k && i + j < n; ++j) {
                maxVal = max(maxVal, arr[i + j]);
                maxSum = max(maxSum, maxVal * (j + 1) + dp[i + j + 1]);
            }

            dp[i] = maxSum;
        }

        return dp[0];
    }
};