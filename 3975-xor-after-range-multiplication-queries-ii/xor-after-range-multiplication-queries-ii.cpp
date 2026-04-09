class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
    
    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long MOD = 1000000007;
        int T = sqrt(n) + 1;
        
        vector<long long> a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = nums[i];
        }
        
        vector<vector<vector<int>>> small_queries(T);
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k >= T) {
                for (int idx = l; idx <= r; idx += k) {
                    a[idx] = (a[idx] * v) % MOD;
                }
            } else {
                small_queries[k].push_back(q);
            }
        }
        
        vector<long long> diff(n, 1);
        for (int k = 1; k < T; ++k) {
            if (small_queries[k].empty()) continue;
            
            fill(diff.begin(), diff.end(), 1);
            
            for (auto& q : small_queries[k]) {
                int l = q[0], r = q[1], v = q[3];
                diff[l] = (diff[l] * v) % MOD;
                
                long long steps = (r - l) / k;
                long long R = l + (steps + 1) * k;
                if (R < n) {
                    diff[R] = (diff[R] * modInverse(v)) % MOD;
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    a[i] = (a[i] * diff[i]) % MOD;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= a[i];
        }
        
        return ans;
    }
};