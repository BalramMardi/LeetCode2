class Solution {
public:
    int maxCoins(vector<int>& nums) {
    int n = nums.size();
    
    // Add 1 before and after nums array for easier calculation
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // DP table to store the results
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    
    // Bottom-up DP
    for (int len = 2; len <= n + 1; ++len) { // Length of the subarray
        for (int i = 0; i <= n + 1 - len; ++i) {
            int j = i + len; // Right boundary of the subarray
            for (int k = i + 1; k < j; ++k) { // Position to burst the last balloon
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }
    }
    
    // Return the result for the full range
    return dp[0][n + 1];
}

};