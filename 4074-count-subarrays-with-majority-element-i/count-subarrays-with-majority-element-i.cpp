class Solution {
public:
    typedef long long ll;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

class Fenwick
{
public:
    int n;
    vector<ll> bit;

    Fenwick(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, ll val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll query(int idx)
    {
        ll sum = 0;
        while (idx > 0)
        {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};
    
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ll> prefix(n + 1, 0);

        rep(i, 0, n)
        {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<ll> comp = prefix;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick tree(comp.size());

        ll ans = 0;

        rep(i, 0, n + 1)
        {

            int idx = lower_bound(comp.begin(), comp.end(), prefix[i]) - comp.begin() + 1;

            ans += tree.query(idx - 1);

            tree.update(idx, 1);
        }

        return ans;
    }
};