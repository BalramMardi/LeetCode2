class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> countMap;
        long long prefixXor = 0, result = 0;

        countMap[0] = 1;

        for(int num : nums){

            prefixXor ^= num;
            result += countMap[prefixXor];
            countMap[prefixXor]++;
        }
        return result;
        
    }
};