class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp.insert({0,-1});
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum -= 1;
            }
            else if(nums[i]==1){
                sum += 1;
            }

            if(mp.find(sum)!=mp.end()){
                int idx = mp[sum];
                int diff = i-idx;
                ans = max(diff,ans);
            }
            else{
                mp.insert({sum,i});
            }
        }
        return ans;
    }
};