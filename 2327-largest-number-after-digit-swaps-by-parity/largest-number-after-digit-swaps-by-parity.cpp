class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<char> odd, even;
        for (char c : s) {
            if ((c - '0') % 2) odd.push_back(c);
            else even.push_back(c);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());
        int oi = 0, ei = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if ((s[i] - '0') % 2) s[i] = odd[oi++];
            else s[i] = even[ei++];
        }
        return stoi(s);
    }
};