class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0,count=0;
        int n=nums.size();
        int sum=0;
        while(j<n){
            sum+=nums[j];
            if(sum==k)
                count++;
            if(mp.find(sum-k)!=mp.end())
                count+=mp[sum-k];
            mp[sum]++;
            j++;
        }
        return count;
    }
};