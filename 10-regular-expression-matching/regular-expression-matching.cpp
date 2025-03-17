class Solution{
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        // Base Case
        dp[0][0] = true;
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Ignore '*'
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // Use '*'
                    }
                }
            }
        }

        return dp[n][m];
    }
};


/* class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;

        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};
 */

/* class Solution {
public:
    bool isMatch(string s, string p) {

        int slen = s.length();
        int plen = p.length();
        vector<vector<bool>> dp(plen + 1, vector<bool>(slen + 1, false));
        for (int i = 0; i <= plen; i++) {
            for (int j = 0; j <= slen; j++) {
                if (i == 0 and j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    if (p[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if (p[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];

                        if (i >= 2 &&
                            (p[i - 2] == s[j - 1] || p[i - 2] == '.')) {
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    } else if (p[i - 1] == s[j - 1] or p[i - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[plen][slen];
    }
}; */