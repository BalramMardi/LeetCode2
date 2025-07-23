class Solution {
public:
    int getPoints(string &s, char first, char second, int point) {
        stack<char> st;
        int score = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                score += point;
            } else {
                st.push(ch);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += getPoints(s, 'a', 'b', x);
            total += getPoints(s, 'b', 'a', y);
        } else {
            total += getPoints(s, 'b', 'a', y);
            total += getPoints(s, 'a', 'b', x);
        }

        return total;
    }
};