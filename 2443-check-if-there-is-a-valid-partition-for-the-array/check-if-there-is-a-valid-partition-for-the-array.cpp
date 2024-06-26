class Solution {
public:

    vector<int> dp;

    Solution() : dp(100001, -1) {} 

    bool solve(vector<int>& nums, int idx) {

        if (idx >= nums.size()) {
            return true;
        }

        bool result = false;

        if(dp[idx]!=-1){
            return dp[idx];
        }

        if (idx + 1 < nums.size() and nums[idx] == nums[idx + 1]) {
            result |= solve(nums, idx + 2);
        }

        if (idx + 2 < nums.size() and nums[idx] == nums[idx + 1] and
            nums[idx + 2] == nums[idx + 1]) {
            result |= solve(nums, idx + 3);
        }

        if ((idx + 2 < nums.size()) and (nums[idx + 1] - nums[idx] == 1) and
            (nums[idx + 2] - nums[idx + 1] == 1))

        {
            result |= solve(nums, idx + 3);
        }

        return dp[idx]=result;
    }
    bool validPartition(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1); 
        return solve(nums,0);
    }
};