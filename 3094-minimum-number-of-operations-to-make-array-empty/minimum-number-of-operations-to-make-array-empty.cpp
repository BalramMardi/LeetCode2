class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto &it:mp){

            int freq = it.second;

            if(freq== 1){
                return -1;
            }

            count += ceil((double)freq /3);

        }

        return count;
    }
};