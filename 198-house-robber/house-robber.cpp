
class Solution {
public:
    int robUtil(int index, vector<int>& nums, vector<int>& dp) {
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];

        
        int rob = nums[index] + robUtil(index - 2, nums, dp);
        int skip = robUtil(index - 1, nums, dp);

        return dp[index] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robUtil(n - 1, nums, dp);
    }
};

/* class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1);

        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }

        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max((dp[i-2]+nums[i]),dp[i-1]);
        }

        return dp[nums.size()-1];
    }
}; */