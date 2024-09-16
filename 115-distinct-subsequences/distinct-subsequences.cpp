#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        
        // dp[i][j] = number of subsequences of s[0...i-1] that equal t[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base case: An empty t can be matched by one subsequence (the empty subsequence)
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i-1] == t[j-1]) {
                    // Characters match: two options, take it or leave it
                    dp[i][j] = (long long)dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // Characters don't match: skip the character in s
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        // The answer is in dp[m][n]
        return dp[m][n];
    }
};
