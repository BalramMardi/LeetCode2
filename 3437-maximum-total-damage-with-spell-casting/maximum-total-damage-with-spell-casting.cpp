class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty())
            return 0;

        unordered_map<int, int> count;
        for (int p : power) {
            count[p]++;
        }

        vector<int> uniquePowers;
        for (auto& pair : count) {
            uniquePowers.push_back(pair.first);
        }
        sort(uniquePowers.begin(), uniquePowers.end());

        int n = uniquePowers.size();
        if (n == 0)
            return 0;

        vector<long long> dp(n, 0);
        dp[0] = (long long)uniquePowers[0] * count[uniquePowers[0]];

        for (int i = 1; i < n; ++i) {
            long long current_sum =
                (long long)uniquePowers[i] * count[uniquePowers[i]];
            int target = uniquePowers[i] - 3;

           
            auto it = upper_bound(uniquePowers.begin(),
                                  uniquePowers.begin() + i, target);
            if (it != uniquePowers.begin()) {
                int j = distance(uniquePowers.begin(), it) - 1;
                current_sum += dp[j];
            }

            dp[i] = max(dp[i - 1], current_sum);
        }

        return dp.back();
    }
};