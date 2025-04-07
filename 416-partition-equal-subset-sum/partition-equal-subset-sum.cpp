class Solution {
public:
    bool canPartitionHelper(const vector<int>& nums, int target) {
        vector<bool> dp(target + 1, false);
        dp[0] = true; 

        for (int num : nums) {
            for (int j = target; j >= num; --j) { 
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }

    bool canPartition(const vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum % 2 != 0)
            return false;

        int subset_sum = total_sum / 2;
        return canPartitionHelper(nums, subset_sum);
    }
};
