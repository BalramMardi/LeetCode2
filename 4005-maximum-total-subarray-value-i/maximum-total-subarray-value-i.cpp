class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.empty()) return 0;

        int mini = nums[0];
        int maxi = nums[0];
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        long long val = (long long)maxi - (long long)mini;
        val = val * k;

        return val;
    }
};