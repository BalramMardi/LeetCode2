class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {

        int n = nums.size();
        unordered_map<ll, ll> vecLeft, vecRight;

        vecLeft.reserve(n * 2);
        
        vecRight.reserve(n * 2);
    
        for (int i = 0; i < nums.size(); i++)
        {
            vecRight[nums[i]]++;
        }
    
        ll ans = 0;
    
        for (int j = 0; j < n; j++)
        {
            ll v = nums[j];
    
            if (--vecRight[v] == 0)
                vecRight.erase(v);
    
            ll wanted = 2 * v;
    
            if (auto itL = vecLeft.find(wanted); itL != vecLeft.end())
            {
                if (auto itR = vecRight.find(wanted); itR != vecRight.end())
                {
                    ans = (ans + (itL->second % MOD) * (itR->second % MOD)) % MOD;
                }
            }
    
            vecLeft[v]++;
        }

        return ans;
    }
};