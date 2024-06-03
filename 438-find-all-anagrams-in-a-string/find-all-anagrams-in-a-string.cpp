class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26, 0);

        int m = s.length();
        int n = p.length();

        if (m < n)
            return {}; 
        for (char& ch : p)
            arr[ch - 'a']++;

        vector<int> result;

        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']--;
        }
        if (arr == vector<int>(26, 0)) {
            result.push_back(0);
        }


        for (int i = n; i < m; i++) {
            arr[s[i - n] - 'a']++;
            arr[s[i] - 'a']--;
            if (arr == vector<int>(26, 0)) {
                result.push_back(i - n + 1);
            }
        }

        return result;
    }
};