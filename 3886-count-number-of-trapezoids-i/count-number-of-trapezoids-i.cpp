class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int, int> mp;
    
        for (auto &p : points)
        {
            mp[p[1]]++;
        }
    
        vector<ll> counts;
    
        for (auto &[x, n] : mp)
        {
            if (n > 1)
            {
                ll k = 1LL * n * (n - 1) / 2;
                counts.push_back(k);
            }
        }
    
        ll sum = 0;

        ll squareSum=0;

        for(ll val : counts){

            sum = (sum + val) % MOD;
            squareSum = (squareSum + val *val %MOD)%MOD;
        }

        ll res=(sum * sum % MOD - squareSum + MOD)%MOD;

        res = res*((MOD+1)/2)%MOD;
        
    
        return res;
    }
};