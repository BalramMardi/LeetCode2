class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0,count=0;
        int n=nums.size();
        int sum=0;
        mp[0]=1;
        while(j<n){
            sum+=nums[j];
            int rem = sum - k;
            if(mp.find(sum-k)!=mp.end())
                count+=mp[rem];
            mp[sum]++;
            j++;
        }
        return count;
    }
};