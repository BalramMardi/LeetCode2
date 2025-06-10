class Solution {
public:
    int dp[21][2001];

    int solve(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) return sum == target;
        if (dp[i][sum + 1000] != -1) return dp[i][sum + 1000];

        int plus = solve(nums, i + 1, sum + nums[i], target);
        int minus = solve(nums, i + 1, sum - nums[i], target);
        return dp[i][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, target);
    }
};





















/* class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];
        if (totalSum - d < 0)
            return 0;    
        if ((totalSum - d) % 2)
            return 0;
        int sum = (totalSum - d) / 2; 
        vector <int> prev(sum+1, 0), cur(sum+1, 0);
        if (arr[0] == 0)
            prev[0] = 2;
        else  
            prev[0] = 1;
        if (arr[0] != 0 && arr[0] <= sum)    
            prev[arr[0]] = 1;
        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= sum; target++) {
                int notTaken = prev[target];
                int taken = 0;
                if (arr[idx] <= target)
                    taken = prev[target-arr[idx]];
                cur[target] = (notTaken + taken);
            }
            prev = cur;
        }
        return prev[sum];
    }
}; */