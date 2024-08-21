class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26);
        int res = 0;
        int maxCount = 0; 
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            arr[s[r] - 'A']++;
            maxCount = std::max(maxCount, arr[s[r] - 'A']);

            // Now we check if our current window is valid or not
            if (r - l + 1 - maxCount > k) { 
                // This means the number of replacements is more than allowed (k)
                arr[s[l] - 'A']--;  
                l++;
            }
            res = std::max(res, r - l + 1);
        }

        return res;
    }
};
