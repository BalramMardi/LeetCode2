class Solution {
public:
    int maxDistance(string s, int k) {
        int vertical = 0, horizontal = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    vertical++;
                    break;
                case 'S':
                    vertical--;
                    break;
                case 'E':
                    horizontal++;
                    break;
                case 'W':
                    horizontal--;
                    break;
            }
            ans = max(ans, min(abs(vertical) + abs(horizontal) + k * 2, i + 1));
        }
        return ans;
    }
};