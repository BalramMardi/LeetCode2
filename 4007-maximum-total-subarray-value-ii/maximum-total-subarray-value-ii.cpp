class SparseTable {
    int n, maxLog;
    vector<vector<int>> max_st, min_st;
    vector<int> lg;
public:
    SparseTable(const vector<int>& nums) {
        n = nums.size();
        maxLog = 32 - __builtin_clz(n);
        max_st.assign(n, vector<int>(maxLog));
        min_st.assign(n, vector<int>(maxLog));
        lg.assign(n + 1, 0);
        
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            max_st[i][0] = nums[i];
            min_st[i][0] = nums[i];
        }
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                max_st[i][j] = max(max_st[i][j - 1], max_st[i + (1 << (j - 1))][j - 1]);
                min_st[i][j] = min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryMax(int l, int r) {
        int k = lg[r - l + 1];
        return max(max_st[l][k], max_st[r - (1 << k) + 1][k]);
    }

    int queryMin(int l, int r) {
        int k = lg[r - l + 1];
        return min(min_st[l][k], min_st[r - (1 << k) + 1][k]);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        
        priority_queue<tuple<long long, int, int>> pq;
        
        for (int l = 0; l < n; l++) {
            long long val = st.queryMax(l, n - 1) - st.queryMin(l, n - 1);
            pq.push({val, l, n - 1});
        }
        
        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if (r > l) {
                long long next_val = st.queryMax(l, r - 1) - st.queryMin(l, r - 1);
                pq.push({next_val, l, r - 1});
            }
        }
        return ans;
    }
};