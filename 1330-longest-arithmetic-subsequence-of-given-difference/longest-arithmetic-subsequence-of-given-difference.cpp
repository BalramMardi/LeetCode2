class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int maxLen = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            maxLen = max(maxLen, dp[x]);
        }

        return maxLen;
    }
};
