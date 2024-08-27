class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0, mini = INT_MAX, current_sum = 0;

        for (int r = 0; r < n;) {
            current_sum += nums[r++];               
            while(l<n && current_sum > target)       
            {
                current_sum -= nums[l++];
            }
            if(current_sum == target)
            mini = min(mini, n-(r-l));      
        }
        return mini == INT_MAX ? -1 : mini;
    }
};