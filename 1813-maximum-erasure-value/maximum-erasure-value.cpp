class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0, sum = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            while (mp.count(nums[r])) {
                mp[nums[l]]--;
                sum -= nums[l];
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            mp[nums[r]]++;
            sum += nums[r];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
