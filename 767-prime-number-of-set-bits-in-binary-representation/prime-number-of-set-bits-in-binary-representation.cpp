class Solution {
public:
    static constexpr int MAXI = 30;
    vector<bool> isPrime;

    Solution() {
        isPrime.assign(MAXI + 1, true);
        primehelper();
    }

    void primehelper() {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAXI; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAXI; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int cnt = __builtin_popcount(i);
            if (isPrime[cnt]) ans++;
        }
        return ans;
    }
};