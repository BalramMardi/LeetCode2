struct SegTree {
    int n;
    vector<int> tree;
    SegTree(const vector<int>& a) {
        n = a.size();
        tree.assign(2 * n, 0);
        for (int i = 0; i < n; i++) tree[n + i] = a[i];
        for (int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length(), total_ones = count(s.begin(), s.end(), '1');
        vector<int> S, E, A, ans;
        
        for (int i = 0, start = -1; i <= n; ++i) {
            if (i < n && s[i] == '0') {
                if (start == -1) start = i;
            } else if (start != -1) {
                S.push_back(start);
                E.push_back(i - 1);
                start = -1;
            }
        }
        
        for (size_t i = 1; i < S.size(); ++i) {
            A.push_back((E[i - 1] - S[i - 1] + 1) + (E[i] - S[i] + 1));
        }
        SegTree st(A);
        
        for (auto& q : queries) {
            int L = q[0], R = q[1];
            int a = lower_bound(E.begin(), E.end(), L) - E.begin();
            int b = upper_bound(S.begin(), S.end(), R) - S.begin() - 1;
            
            if (a >= b || a == E.size() || b < 0) {
                ans.push_back(total_ones);
            } else if (a + 1 == b) {
                ans.push_back(total_ones + (E[a] - max(L, S[a]) + 1) + (min(R, E[b]) - S[b] + 1));
            } else {
                int g1 = (E[a] - max(L, S[a]) + 1) + (E[a + 1] - S[a + 1] + 1);
                int g2 = (min(R, E[b]) - S[b] + 1) + (E[b - 1] - S[b - 1] + 1);
                int mx = max({g1, g2, a + 1 <= b - 2 ? st.query(a + 1, b - 2) : 0});
                ans.push_back(total_ones + mx);
            }
        }
        return ans;
    }
};