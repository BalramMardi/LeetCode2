class Solution {
public:
    bool isPalindrome(const string &str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int longestPalindrome(string s, string t) {
        int maxLen = 0;
        int n = s.size(), m = t.size();

        // Generate all possible substrings from s
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                string sub_s = s.substr(i, j - i);

                // Generate all possible substrings from t
                for (int k = 0; k <= m; k++) {
                    for (int l = k; l <= m; l++) {
                        string sub_t = t.substr(k, l - k);
                        string combined = sub_s + sub_t;

                        // Check if the combined string is a palindrome
                        if (isPalindrome(combined)) {
                            maxLen = max(maxLen, (int)combined.size());
                        }
                    }
                }
            }
        }

        return maxLen;
    }
};