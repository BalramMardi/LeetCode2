class Solution {
    vector<int> tree;
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int left_max = query(2 * node, start, mid, l, r);
        int right_max = query(2 * node + 1, mid + 1, end, l, r);
        return max(left_max, right_max);
    }

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        max_x++;
        
        tree.assign(4 * max_x, 0);
        set<int> obs;
        obs.insert(0);
        vector<bool> res;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obs.upper_bound(x);
                int nxt = -1;
                if (it != obs.end()) {
                    nxt = *it;
                }
                int prv = *prev(it);
                
                update(1, 0, max_x, x, x - prv);
                if (nxt != -1) {
                    update(1, 0, max_x, nxt, nxt - x);
                }
                obs.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obs.upper_bound(x);
                int prv = *prev(it);
                
                int max_gap = query(1, 0, max_x, 0, prv);
                max_gap = max(max_gap, x - prv);
                
                res.push_back(max_gap >= sz);
            }
        }
        return res;
    }
};