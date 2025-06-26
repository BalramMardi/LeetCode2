class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeros = 0;
        for (char c : s) {
            if (c == '0') zeros++;
        }

        int ones = 0;
        long long val = 0;
        int power = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (power < 32 && val + (1LL << power) <= k) {
                    val += (1LL << power);
                    ones++;
                } else {
                    break;
                }
            }
            power++;
        }

        return zeros + ones;
    }
};
