#include <bits/stdc++.h>

using namespace std;

struct LazyTag {
    int to_add = 0;

    LazyTag& operator+=(const LazyTag& other) {
        this->to_add += other.to_add;
        return *this;
    }

    bool has_tag() const { 
        return to_add != 0; 
    }

    void clear() { 
        to_add = 0; 
    }
};

struct Node {
    int min_val = 0;
    int max_val = 0;
    LazyTag tag;
};

class SegmentTree {
    int n;
    vector<Node> tree;

    void apply(int i, const LazyTag& tag) {
        tree[i].min_val += tag.to_add;
        tree[i].max_val += tag.to_add;
        tree[i].tag += tag;
    }

    void push_down(int i) {
        if (tree[i].tag.has_tag()) {
            apply(i << 1, tree[i].tag);
            apply(i << 1 | 1, tree[i].tag);
            tree[i].tag.clear();
        }
    }

    void push_up(int i) {
        tree[i].min_val = min(tree[i << 1].min_val, tree[i << 1 | 1].min_val);
        tree[i].max_val = max(tree[i << 1].max_val, tree[i << 1 | 1].max_val);
    }

    void build(const vector<int>& data, int l, int r, int i) {
        if (l == r) {
            tree[i].min_val = tree[i].max_val = data[l - 1];
            return;
        }
        int mid = l + (r - l) / 2;
        build(data, l, mid, i << 1);
        build(data, mid + 1, r, i << 1 | 1);
        push_up(i);
    }

    void update_range(int ql, int qr, const LazyTag& tag, int l, int r, int i) {
        if (ql <= l && r <= qr) {
            apply(i, tag);
            return;
        }
        push_down(i);
        int mid = l + (r - l) / 2;
        if (ql <= mid) update_range(ql, qr, tag, l, mid, i << 1);
        if (qr > mid)  update_range(ql, qr, tag, mid + 1, r, i << 1 | 1);
        push_up(i);
    }

    int query_last_occurrence(int ql, int qr, int target, int l, int r, int i) {
        if (tree[i].min_val > target || tree[i].max_val < target) {
            return -1;
        }
        if (l == r) {
            return l;
        }

        push_down(i);
        int mid = l + (r - l) / 2;
        
        if (qr >= mid + 1) {
            int res = query_last_occurrence(ql, qr, target, mid + 1, r, i << 1 | 1);
            if (res != -1) return res;
        }

        if (l <= qr && mid >= ql) {
            return query_last_occurrence(ql, qr, target, l, mid, i << 1);
        }
        return -1;
    }

public:
    SegmentTree(const vector<int>& data) : n(data.size()) {
        tree.resize(n * 4 + 1);
        build(data, 1, n, 1);
    }

    void add(int l, int r, int val) {
        if (l > r) return;
        update_range(l, r, {val}, 1, n, 1);
    }

    int find_last(int start_idx, int target) {
        if (start_idx > n) return -1;
        return query_last_occurrence(start_idx, n, target, 1, n, 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        map<int, queue<int>> pos_map;
        auto get_weight = [](int x) { return (x % 2 == 0) ? 1 : -1; };

        vector<int> prefix_sum(n);
        int current_sum = 0;
        
        for (int i = 0; i < n; i++) {
            auto& q = pos_map[nums[i]];
            if (q.empty()) {
                current_sum += get_weight(nums[i]);
            }
            prefix_sum[i] = current_sum;
            q.push(i + 1);
        }

        SegmentTree st(prefix_sum);
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            int last_idx = st.find_last(i + max_len, 0);
            if (last_idx != -1) {
                max_len = max(max_len, last_idx - i);
            }

            int val = nums[i];
            int weight = get_weight(val);
            pos_map[val].pop();
            
            int next_occurrence = pos_map[val].empty() ? n + 1 : pos_map[val].front();
            
            st.add(i + 1, next_occurrence - 1, -weight);
        }

        return max_len;
    }
};