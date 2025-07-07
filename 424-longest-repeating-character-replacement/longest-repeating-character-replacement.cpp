class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26);
        int res = 0;
        int maxCount = 0; 
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            arr[s[r] - 'A']++;
            maxCount = max(maxCount, arr[s[r] - 'A']);

            if (r - l + 1 - maxCount > k) { 
                arr[s[l] - 'A']--;  
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
