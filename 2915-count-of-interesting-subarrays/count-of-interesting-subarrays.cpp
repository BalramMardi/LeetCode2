class Solution {
public:
    typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        
        unordered_map<int,ll> mp;
        mp[0]=1;
        ll count = 0;
        int prefix =0;
        for(int num : nums){
            prefix += (num % m == k);
            int modValue = prefix % m;
            int needed = (modValue - k + m)%m;

            if(mp.find(needed)!= mp.end()){
                count += mp[needed];
            }
            
            mp[modValue]++;
        }

        return count;
    }
};