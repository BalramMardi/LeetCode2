class Solution {
public:
    bool canAliceWin(int n) {
        int t = 10, k = 0;
        while (t <= n) {
            n -= t;
            t--;
            k++;
        }
        return k % 2 == 1;
    }
};