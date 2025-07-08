/* class Solution {
public:
    int minOperations(vector<int>& nums, int x) {        
        int n    = nums.size();
        int sum  = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
            return -1;
        int restSum  = sum-x;
        int longest  = INT_MIN;
        sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            if(mp.count(sum-restSum)) {
                longest = max(longest, i-mp[sum-restSum]);
            }
        }
        
        return longest==INT_MIN?-1:n-longest;
    }
}; */


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0, mini = INT_MAX, current_sum = 0;

        for (int r = 0; r < n;r++) {
            current_sum += nums[r];               
            while(l<n && current_sum > target)       
            {
                current_sum -= nums[l++];
            }
            if(current_sum == target)
                mini = min(mini, n-(r-l+1));      
        }
        return mini == INT_MAX ? -1 : mini;
    }
};