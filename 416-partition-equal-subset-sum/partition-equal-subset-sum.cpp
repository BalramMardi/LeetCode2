/*
    Given non-empty, non-negative integer array nums, find if:
    Can be partitionined into 2 subsets such that sums are equal
    Ex. nums = [1,5,11,5] -> true, [1,5,5] & [11], both add to 11

    Maintain DP set, for each num, check if num in set + curr = target
    If not, add curr to every num in set we checked & iterate

    Time: O(n x sum(nums))
    Space: O(sum(nums))
*/

class Solution {
public:
    bool canPartitionHelper(const vector<int>& nums, int n, int sum) {
        vector<vector<bool>> dp(n + 1,vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }

    bool canPartition(const vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum % 2 != 0)
            return false;

        int subset_sum = total_sum / 2;
        return canPartitionHelper(nums, nums.size(), subset_sum);
    }
};
