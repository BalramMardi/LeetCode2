class Solution {
public:
    typedef long long ll;
    int minSubarray(vector<int>& nums, int p) {
        ll total = accumulate(nums.begin(),nums.end(),0LL);
        ll target = total % p;

        if (target == 0) return 0;

        unordered_map<int,int> mp;
        mp[0]=-1;
        int currentSum = 0;
        int mini = nums.size();
        for(int i=0;i<nums.size();i++){
            
            currentSum = (currentSum + nums[i])%p;
            int needed = (currentSum - target + p)%p;

            if(mp.find(needed)!= mp.end()){
                mini = min(mini, i-mp[needed]);
            }

            // mp.insert({currentSum,i});
            mp[currentSum]=i;

        }

        return mini == nums.size() ? -1 : mini;
    }
};