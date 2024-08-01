class Solution {
public:
    int dp[10001];
    int solve(vector<int>& nums, int idx) {
        if (idx >= nums.size() - 1) return 0;

        if(dp[idx] !=-1){
            return dp[idx];
        }
        
        int minJumps = nums.size() + 1;

        
        for (int step = nums[idx]; step >= 1; --step) {
            int jumps = 1 + solve(nums, idx + step);
            minJumps = min(minJumps, jumps);
        }
        
        return dp[idx] =  minJumps;
    }

    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0);
    }
};