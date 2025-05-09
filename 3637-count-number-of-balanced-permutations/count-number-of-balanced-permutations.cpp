class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int totalSum = 0, n = num.size();
        vector<int> digitCount(10);

        for (char ch : num) {
            int d = ch - '0';
            digitCount[d]++;
            totalSum += d;
        }

        if (totalSum % 2 != 0) return 0;
        int targetSum = totalSum / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> prefixSum(11);
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1));
        
        vector<vector<vector<long long>>> memo(10, vector<vector<long long>>(targetSum + 1, vector<long long>(maxOdd + 1, -1)));

        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        for (int i = 9; i >= 0; i--) {
            prefixSum[i] = prefixSum[i + 1] + digitCount[i];
        }

        return dfs(0, 0, maxOdd, targetSum, digitCount, prefixSum, comb, memo);
    }

private:
    long long dfs(int pos, int currSum, int oddCount, int targetSum, vector<int>& digitCount,
                  vector<int>& prefixSum, vector<vector<long long>>& comb, 
                  vector<vector<vector<long long>>>& memo) {
        if (oddCount < 0 || prefixSum[pos] < oddCount || currSum > targetSum) {
            return 0;
        }
        if (pos > 9) {
            return currSum == targetSum && oddCount == 0;
        }
        if (memo[pos][currSum][oddCount] != -1) {
            return memo[pos][currSum][oddCount];
        }

        int evenCount = prefixSum[pos] - oddCount;
        long long res = 0;
        for (int i = max(0, digitCount[pos] - evenCount); i <= min(digitCount[pos], oddCount); i++) {
            long long ways = comb[oddCount][i] * comb[evenCount][digitCount[pos] - i] % MOD;
            res = (res + ways * dfs(pos + 1, currSum + i * pos, oddCount - i, targetSum, digitCount, prefixSum, comb, memo) % MOD) % MOD;
        }
        memo[pos][currSum][oddCount] = res;
        return res;
    }
};
