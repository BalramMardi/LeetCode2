class Solution {
public:
    int longestBalanced(string s) {

        int n = s.length();
        int max_len = 0;

        // --- Case 1: 1 Distinct Character ---
        // Find longest run of identical characters
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_len = max(max_len, current_run);
        }

        // --- Case 2: 2 Distinct Characters ---
        // Pairs to check: {a,b} (forbid c), {b,c} (forbid a), {a,c} (forbid b)
        vector<pair<char, char>> pairs = {{'a', 'b'}, {'b', 'c'}, {'a', 'c'}};

        for (auto p : pairs) {
            char c1 = p.first;
            char c2 = p.second;
            char forbidden;
            if (c1 != 'a' && c2 != 'a')
                forbidden = 'a';
            else if (c1 != 'b' && c2 != 'b')
                forbidden = 'b';
            else
                forbidden = 'c';

            // Map stores: balance -> first index where this balance occurred
            unordered_map<int, int> mp;
            mp[0] = -1;
            int balance = 0;

            for (int i = 0; i < n; ++i) {
                if (s[i] == forbidden) {
                    mp.clear();
                    mp[0] = i;
                    balance = 0;
                } else {
                    if (s[i] == c1)
                        balance++;
                    else if (s[i] == c2)
                        balance--;

                    if (mp.count(balance)) {
                        max_len = max(max_len, i - mp[balance]);
                    } else {
                        mp[balance] = i;
                    }
                }
            }
        }

        // --- Case 3: 3 Distinct Characters ---
        // We need count(a) == count(b) == count(c)
        // We track the state (count(a)-count(b), count(b)-count(c))
        map<pair<int, int>, int> mp3;
        mp3[{0, 0}] = -1;
        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a')
                ca++;
            else if (s[i] == 'b')
                cb++;
            else if (s[i] == 'c')
                cc++;

            pair<int, int> state = {ca - cb, cb - cc};

            if (mp3.count(state)) {
                max_len = max(max_len, i - mp3[state]);
            } else {
                mp3[state] = i;
            }
        }

        return max_len;
    }
};