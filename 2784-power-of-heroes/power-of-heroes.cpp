class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long result = 0;

        long long prefixSum = 0;

        for (int i = 0; i < n; i++) {
            long long max_contribution = (1LL * nums[i] * nums[i]) % MOD;

            result = (result + max_contribution * (prefixSum + nums[i]) % MOD) % MOD;

            prefixSum = (prefixSum * 2 + nums[i]) % MOD;
        }

        return result;
    }
};