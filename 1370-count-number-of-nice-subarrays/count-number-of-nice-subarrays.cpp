class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int oddCount = 0;
        int count = 0;
        for(int num: nums){
            oddCount += (num % 2 != 0);
            int needed = oddCount-k;
            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            mp[oddCount]++;
        }
        return count;
    }
};