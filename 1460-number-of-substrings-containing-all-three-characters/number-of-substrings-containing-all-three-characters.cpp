class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0};
        int l = 0, ans = 0;
        int n = s.length();
        
        for (int r = 0; r < n; ++r) {
            count[s[r] - 'a']++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[l] - 'a']--;
                l++;
            }
            
            ans += l;
        }
        
        return ans;
    }
};