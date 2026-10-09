class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int insertions = 0;
        int i = 0;
        
        while (i < s.length()) {
            if (s[i] == '(') {
                st.push(s[i]);
                i++;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        insertions++;
                    }
                    i += 2;
                } else {
                    if (!st.empty()) {
                        st.pop();
                        insertions++;
                    } else {
                        insertions += 2;
                    }
                    i++;
                }
            }
        }
        
        while (!st.empty()) {
            insertions += 2;
            st.pop();
        }
        
        return insertions;
    }
};