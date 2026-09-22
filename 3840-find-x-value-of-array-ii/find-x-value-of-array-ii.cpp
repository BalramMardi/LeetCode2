struct Node {
    int remain[5];
    int prod;
    Node() {
        memset(remain, 0, sizeof(remain));
        prod = 1;
    }
};

class SegmentTree {
public:
    int n, k;
    vector<Node> tree;

    SegmentTree(const vector<int>& nums, int k) : n(nums.size()), k(k), tree(4 * n) {
        build(nums, 0, 0, n - 1);
    }

    Node merge_nodes(const Node& left, const Node& right) const {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; ++i) {
            res.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            res.remain[(left.prod * i) % k] += right.remain[i];
        }
        return res;
    }

    void build(const vector<int>& nums, int cur, int lo, int hi) {
        if (lo == hi) {
            tree[cur].prod = nums[lo] % k;
            tree[cur].remain[nums[lo] % k] = 1;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        build(nums, 2 * cur + 1, lo, mid);
        build(nums, 2 * cur + 2, mid + 1, hi);
        tree[cur] = merge_nodes(tree[2 * cur + 1], tree[2 * cur + 2]);
    }

    void update(int cur, int lo, int hi, int i, int val) {
        if (lo == hi) {
            memset(tree[cur].remain, 0, sizeof(tree[cur].remain));
            tree[cur].prod = val % k;
            tree[cur].remain[val % k] = 1;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (i <= mid) {
            update(2 * cur + 1, lo, mid, i, val);
        } else {
            update(2 * cur + 2, mid + 1, hi, i, val);
        }
        tree[cur] = merge_nodes(tree[2 * cur + 1], tree[2 * cur + 2]);
    }

    Node query(int cur, int lo, int hi, int ql, int qr) const {
        if (ql <= lo && hi <= qr) {
            return tree[cur];
        }
        int mid = lo + (hi - lo) / 2;
        if (qr <= mid) {
            return query(2 * cur + 1, lo, mid, ql, qr);
        } else if (ql > mid) {
            return query(2 * cur + 2, mid + 1, hi, ql, qr);
        }
        return merge_nodes(query(2 * cur + 1, lo, mid, ql, qr), query(2 * cur + 2, mid + 1, hi, ql, qr));
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());
        int n = nums.size();
        
        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            
            st.update(0, 0, n - 1, index, value);
            Node res = st.query(0, 0, n - 1, start, n - 1);
            ans.push_back(res.remain[x]);
        }
        
        return ans;
    }
};