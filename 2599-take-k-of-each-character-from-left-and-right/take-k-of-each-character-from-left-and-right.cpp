class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
    vector<int> count(3, 0); 

 
    for (char c : s) {
        count[c - 'a']++;
    }

    
    for (int c : count) {
        if (c < k) return -1;
    }

    int max_removal = 0;
    vector<int> current_count(3, 0); 
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_count[s[right] - 'a']++;

        while (current_count[0] > count[0] - k ||
               current_count[1] > count[1] - k ||
               current_count[2] > count[2] - k) {
            current_count[s[left] - 'a']--;
            left++;
        }

        max_removal = max(max_removal, right - left + 1);
    }

    return n - max_removal;
    }
};