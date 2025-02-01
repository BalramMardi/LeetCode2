
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<>> heap;
        vector<char> ans;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (!heap.empty()) {
                    auto [ch, index] = heap.top(); heap.pop();
                    ans[-index] = 0;
                }
            } else {
                heap.emplace(s[i], -i);
            }
            ans.push_back(s[i]);
        }
        
        string result;
        for (char c : ans) {
            if (c && c != '*') result += c;
        }
        return result;
    }
};