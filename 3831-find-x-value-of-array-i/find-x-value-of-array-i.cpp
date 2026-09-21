class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> nextDp(k, 0);
            int numMod = num % k;
            nextDp[numMod] = 1;
            for (int i = 0; i < k; ++i) {
                if (dp[i] > 0) {
                    int nextMod = (1LL * i * numMod) % k;
                    nextDp[nextMod] += dp[i];
                }
            }
            for (int i = 0; i < k; ++i) {
                ans[i] += nextDp[i];
                dp[i] = nextDp[i];
            }
        }
        return ans;
    }
};