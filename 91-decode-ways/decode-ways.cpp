class Solution {
public:
    int helper(int i, string &s, vector<int> &dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int res = helper(i + 1, s, dp);  // single digit
        if (i + 1 < s.size()) {
            int twoDigit = stoi(s.substr(i, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                res += helper(i + 2, s, dp);  // two digit
            }
        }
        return dp[i] = res;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, dp);
    }
};

/* 
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        int n = s.size();
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int ones = stoi(s.substr(i - 1, 1));
            if (ones >= 1 && ones <= 9) {
                dp[i] += dp[i - 1];
            }
            int tens = stoi(s.substr(i - 2, 2));
            if (tens >= 10 && tens <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};
 */