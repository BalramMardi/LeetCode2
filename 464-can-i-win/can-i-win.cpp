class Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        return canWin(0, desiredTotal, maxChoosableInteger);
    }

    bool canWin(int mask, int total, int n) {
        if (memo.count(mask)) return memo[mask];

        for (int i = 1; i <= n; i++) {
            if (!(mask & (1 << (i - 1)))) {
                if (i >= total) return memo[mask] = true;

                int newMask = mask | (1 << (i - 1));
                if (!canWin(newMask, total - i, n)) {
                    return memo[mask] = true;
                }
            }
        }

        return memo[mask] = false;
    }
};
