class Solution{
public:
int dp[2001][2001];
bool isMatchHelper(const string& s, const string& p, int i, int j) {
   
    if (j == p.length()) {
        return i == s.length(); 
    }

    if (i == s.length()) {
        // If string is exhausted, pattern can only match if remaining pattern is all '*'
        for (int k = j; k < p.length(); k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // If current characters match or pattern has '?'
    if (s[i] == p[j] || p[j] == '?') {
        return dp[i][j] = isMatchHelper(s, p, i + 1, j + 1);
    }

    // If pattern has '*'
    if (p[j] == '*') {
        // Case 1: '*' matches zero characters (skip '*')
        bool skipStar = isMatchHelper(s, p, i, j + 1);
        // Case 2: '*' matches one or more characters (consume one character in string)
        bool consumeChar = isMatchHelper(s, p, i + 1, j);
        return dp[i][j] = skipStar || consumeChar;
    }

   
    return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    memset(dp,-1,sizeof(dp));
    return isMatchHelper(s, p, 0, 0);
}
};




/* class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        
        return dp[m][n];
    }
}; */
