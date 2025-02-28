class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        if (A.empty()) return 0;

        int len = A.size();
        unordered_map<int, int> m;
        vector<vector<int>> dp(len, vector<int>(len, 2));

        for (int i = 0; i < len; i++) {
            m[A[i]] = i;
        }

        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int k = A[i] + A[j];
                if (m.find(k) != m.end()) {
                    int index = m[k];
                    dp[j][index] = dp[i][j] + 1;
                    res = max(res, dp[j][index]);
                }
            }
        }

        return res >= 3 ? res : 0;
    }
};


/* class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 0;

        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < k; ++j) {
                int prev = arr[k] - arr[j];
                if (prev < arr[j] && index.count(prev)) {
                    int i = index[prev];
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
}; */


/* class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<vector<int>> t(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int max_length = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp, t);
                if (length >= 3) {
                    max_length = max(max_length, length);
                }
            }
        }
        return max_length >= 3 ? max_length : 0;
    }
    
private:
    int solve(int j, int k, const vector<int>& arr, const unordered_map<int, int>& mp, vector<vector<int>>& t) {
        if (t[j][k] != -1) return t[j][k];
        
        int target = arr[k] - arr[j];
        if (mp.count(target) && mp.at(target) < j) {
            int i = mp.at(target);
            t[j][k] = solve(i, j, arr, mp, t) + 1;
            return t[j][k];
        }
        
        return t[j][k] = 2;
    }
}; */