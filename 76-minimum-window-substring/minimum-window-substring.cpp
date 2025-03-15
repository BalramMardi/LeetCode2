class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
    
    unordered_map<char, int> freq_t, window;
    for (char c : t) freq_t[c]++;
    
    int left = 0, right = 0, minLen = INT_MAX, start = 0, required = freq_t.size(), formed = 0;

    while (right < s.size()) {
        char c = s[right];
        window[c]++;
        if (freq_t.count(c) && window[c] == freq_t[c]) formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            char lChar = s[left];
            window[lChar]--;
            if (freq_t.count(lChar) && window[lChar] < freq_t[lChar]) formed--;

            left++;
        }

        right++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};