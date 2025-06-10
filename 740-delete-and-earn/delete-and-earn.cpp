class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>& dp) {
        if (i == 0) return points[0];
        if (i == 1) return max(points[0], points[1]);
        if (dp[i] != -1) return dp[i];


        int skip = solve(i - 1, points, dp);
        int take = points[i] + solve(i - 2, points, dp);
        return dp[i] = max(take , skip );
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        for (int num : nums)
            points[num] += num;

        vector<int> dp(maxVal + 1, -1);
        return solve(maxVal, points, dp);
    }
};


/*
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
 */