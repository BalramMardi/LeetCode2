class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<int> freq;
        for (auto const& [key, val] : counts) {
            freq.push_back(val);
        }

        int n = freq.size();
        int m = quantity.size();
        

        vector<int> subset_sum((1<<m), 0);
        for (int mask = 1; mask < (1<<m); ++mask) {
            for (int j = 0; j < m; ++j) {
                if ((mask >> j) & 1) {
                    subset_sum[mask] += quantity[j];
                }
            }
        }

        vector<vector<bool>> dp(n + 1, vector<bool>((1<<m), false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int mask = 1; mask < (1<<m); ++mask) {
              
                //skip
                dp[i][mask] = dp[i - 1][mask];

                //take
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    int remaining_mask = mask ^ submask;
                    if (subset_sum[submask] <= freq[i - 1]) {
                        if (dp[i - 1][remaining_mask]) {
                            dp[i][mask] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[n][(1<<m) - 1];
    }
};