class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);

        for (char c : s1) s1Count[c - 'a']++;

        int window = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            s2Count[s2[i] - 'a']++;

            // Shrink window if needed
            if (i >= window) {
                s2Count[s2[i - window] - 'a']--;
            }

            // Compare counts
            if (s1Count == s2Count) return true;
        }

        return false;
    }
};



/* class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1v (26, 0);
        for (auto c : s1) s1v[c - 'a']++;
        vector<int> s2v (26, 0);
        int l = 0, r = 0;
        while (r < s2.size()) {
            s2v[s2[r]-'a']++;
            if (r - l + 1 == s1.size()) 
                if (s1v == s2v) return true;
            if (r - l + 1 < s1.size()) r++;
            else {
                s2v[s2[l]-'a']--;
                l++;
                r++;
            }
        }
        return false;
    }
}; */