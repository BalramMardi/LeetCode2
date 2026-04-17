class Solution {
public:
    typedef long long ll;
    
    int minMirrorPairDistance(vector<int>& nums) {

        int n=nums.size();

        unordered_map<ll,int> mp;

        int ans = INT_MAX;

        for(int k=0;k<n;k++){

            ans = mp.count(nums[k])?min(ans,k-mp[nums[k]]):ans;

            ll r=0;
            ll t=nums[k];

            while(t){
                r=r*10+t%10;
                t=t/10;
            }

            mp[r]=k;
        }

        if(ans==INT_MAX) return -1;

        return ans;
    }
};