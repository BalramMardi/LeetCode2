class Solution {
public:

    const long long MOD = 1e9 + 7;

    // dp[pos][prevDigit][tight][started]
    // prevDigit: 0..9 and 10 => "no previous"
    long long dp[101][11][2][2];

    string s;

    long long solveDP(int idx, int prev, bool tight, bool started) {
        if (idx == s.size()) {
            return started ? 1 : 0; 
        }

        long long &ans = dp[idx][prev][tight][started];
        if (ans != -1) return ans;

        ans = 0;

        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!started && d == 0) {
                ans = (ans + solveDP(idx + 1, 10, newTight, false)) % MOD;
            } else {
                if (!started) {
                    ans = (ans + solveDP(idx + 1, d, newTight, true)) % MOD;
                } else {
                    if (abs(d - prev) == 1) {
                        ans = (ans + solveDP(idx + 1, d, newTight, true)) % MOD;
                    }
                }
            }
        }

        return ans;
    }

    long long countStepping(string x) {
        s = x;
        memset(dp, -1, sizeof(dp));
        return solveDP(0, 10, true, false);
    }

    int countSteppingNumbers(string low, string high) {
        string lowMinus = low;
        int i = lowMinus.size() - 1;
        while (i >= 0 && lowMinus[i] == '0') {
            lowMinus[i] = '9';
            i--;
        }
        if (i >= 0) lowMinus[i]--;

        long long R = countStepping(high);
        long long L = (low == "0") ? 0 : countStepping(lowMinus);

        return ( (R - L + MOD) % MOD );
    }
};