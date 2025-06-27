class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        string letters;
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] >= k) letters += c;
        }

        queue<string> q;
        q.push("");

        string ans = "";

        while (!q.empty()) {
            int sz = q.size();
            unordered_set<string> nextLevel;

            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();

                for (char c : letters) {
                    string next = cur + c;
                    if (isSubsequence(s, next, k)) {
                        if (next.size() > ans.size() || (next.size() == ans.size() && next > ans))
                            ans = next;
                        nextLevel.insert(next);
                    }
                }
            }

            for (const string& t : nextLevel) q.push(t);
        }

        return ans;
    }

    bool isSubsequence(const string& s, const string& t, int k) {
        int i = 0, j = 0, repeat = 0, n = s.size(), m = t.size();
        while (i < n && repeat < k) {
            if (s[i] == t[j]) {
                j++;
                if (j == m) {
                    j = 0;
                    repeat++;
                }
            }
            i++;
        }
        return repeat == k;
    }
};
