#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = *max_element(nums.begin(), nums.end());
        
        vector<int> arr(n + 1, 0);
        vector<int> dp(n + 1, 0);

        for (int num : nums) {
            arr[num] += num;
        }

        dp[1] = arr[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        return dp[n];
    }
};
