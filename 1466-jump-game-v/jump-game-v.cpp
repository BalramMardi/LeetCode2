class Solution {
public:
    int dfs(vector<int>& arr, int d, int i, vector<int>& dp) {
        if (dp[i] != 0) return dp[i];
        
        int n = arr.size();
        int max_jumps = 1;
        
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[i] > arr[j]; ++j) {
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j, dp));
        }
        
        for (int j = i - 1; j >= max(i - d, 0) && arr[i] > arr[j]; --j) {
            max_jumps = max(max_jumps, 1 + dfs(arr, d, j, dp));
        }
        
        return dp[i] = max_jumps;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 0);
        int ans = 1;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(arr, d, i, dp));
        }
        
        return ans;
    }
};