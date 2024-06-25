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
    bool canPartitionHelper(const std::vector<int> &nums, int n, int sum)
{
    // Create a 2D array to store the results of subproblems
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(sum + 1, false));

    // Initialize the first column as true (0 sum is possible with any subset)
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    // Fill the partition table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // If the current element is greater than the sum, we cannot include it
            if (nums[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // Otherwise, we check if the sum can be obtained by any of:
                // (i) excluding the current element
                // (ii) including the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

// Function to determine if the array can be partitioned into two subsets with equal sum
bool canPartition(const std::vector<int> &nums)
{
    int total_sum = std::accumulate(nums.begin(), nums.end(), 0);

    // If the total sum is odd, it's not possible to partition it into two equal subsets
    if (total_sum % 2 != 0)
        return false;

    // Find if there is a subset with sum equal to half of the total sum
    int subset_sum = total_sum / 2;
    return canPartitionHelper(nums, nums.size(), subset_sum);
}
};
