class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            int bits = 0;
            int temp = i;
            while (temp > 0) {
                bits++;
                temp /= 2;
            }

            ans = ((ans << bits) + i) % MOD;
        }

        return ans;
    }
};