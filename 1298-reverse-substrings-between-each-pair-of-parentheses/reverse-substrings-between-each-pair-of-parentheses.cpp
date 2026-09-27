class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        int d = 1;
        for (int i = 0; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};