class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        string res = "";
        for (int i = 0; i < n; i++) {
            char t = target[i];
            
            bool can_match = false;
            if (freq[t - 'a'] > 0) {
                freq[t - 'a']--;
                string max_rem = "";
                for (int c = 25; c >= 0; c--) {
                    max_rem += string(freq[c], c + 'a');
                }
                if (max_rem > target.substr(i + 1)) {
                    can_match = true;
                }
                freq[t - 'a']++;
            }
            
            if (can_match) {
                res += t;
                freq[t - 'a']--;
            } else {
                bool found = false;
                for (int c = t - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        res += (char)(c + 'a');
                        freq[c]--;
                        found = true;
                        break;
                    }
                }
                if (!found) return "";
                
                for (int c = 0; c < 26; c++) {
                    res += string(freq[c], c + 'a');
                }
                return res;
            }
        }
        return res;
    }
};