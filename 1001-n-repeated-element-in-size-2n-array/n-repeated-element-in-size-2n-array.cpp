class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        int c = nums.size()/2;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;  
            if(mp[nums[i]]==c){
                return nums[i];
            }
        }

        for(auto& [k,f]:mp){
            if(f == c){
                return k;
            }
        }

        return 0;
        
    }
};