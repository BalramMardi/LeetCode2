typedef long long ll;

class Solution {
    ll mod_val = 1e9+7;
    vector<ll> tree_sq;
    vector<ll> tree_sum;
    vector<ll> lazy;

    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = start + (end - start) / 2;
            ll val = lazy[node];
            
            ll left_len = mid - start + 1;
            tree_sq[2 * node + 1] = (tree_sq[2 * node + 1] + 2 * val * tree_sum[2 * node + 1] + val * val % mod_val * left_len) % mod_val;
            tree_sum[2 * node + 1] = (tree_sum[2 * node + 1] + val * left_len) % mod_val;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % mod_val;

            ll right_len = end - mid;
            tree_sq[2 * node + 2] = (tree_sq[2 * node + 2] + 2 * val * tree_sum[2 * node + 2] + val * val % mod_val * right_len) % mod_val;
            tree_sum[2 * node + 2] = (tree_sum[2 * node + 2] + val * right_len) % mod_val;
            lazy[2 * node + 2] = (lazy[2 * node + 2] + val) % mod_val;

            lazy[node] = 0;
        }
    }

    void update_tree(int node, int start, int end, int l, int r, ll val) {
        if (start > end || start > r || end < l) {
            return;
        }
        if (start >= l && end <= r) {
            ll len = end - start + 1;
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] + val * val % mod_val * len) % mod_val;
            tree_sum[node] = (tree_sum[node] + val * len) % mod_val;
            lazy[node] = (lazy[node] + val) % mod_val;
            return;
        }
        push_down(node, start, end);
        int mid = start + (end - start) / 2;
        update_tree(2 * node + 1, start, mid, l, r, val);
        update_tree(2 * node + 2, mid + 1, end, l, r, val);
        
        tree_sq[node] = (tree_sq[2 * node + 1] + tree_sq[2 * node + 2]) % mod_val;
        tree_sum[node] = (tree_sum[2 * node + 1] + tree_sum[2 * node + 2]) % mod_val;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sq.assign(4 * n, 0);
        tree_sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_seen_index;
        ll total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev_idx = -1;
            if (last_seen_index.count(nums[i])) {
                prev_idx = last_seen_index[nums[i]];
            }
            
            update_tree(0, 0, n - 1, prev_idx + 1, i, 1);
            
            total_ans = (total_ans + tree_sq[0]) % mod_val;
            last_seen_index[nums[i]] = i;
        }

        return total_ans;
    }
};