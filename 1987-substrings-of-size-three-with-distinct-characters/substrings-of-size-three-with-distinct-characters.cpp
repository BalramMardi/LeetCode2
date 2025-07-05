class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;
        unordered_map<char, int> freq;
        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;  

            if (right - left + 1 > 3) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            if (right - left + 1 == 3 && freq.size() == 3) {
                count++;
            }
        }
        return count;
    }
};