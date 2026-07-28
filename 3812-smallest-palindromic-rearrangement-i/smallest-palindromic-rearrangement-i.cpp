class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half = n / 2;

        sort(s.begin(), s.begin() + half);

        for (int i = 0; i < half; ++i) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};