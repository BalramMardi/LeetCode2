class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto it: nums){
            mp[it]++;
        }

        for(auto [key,freq] : mp){
            if(freq == 1){
                return key;
            }
        }

        return 0;
    }
};