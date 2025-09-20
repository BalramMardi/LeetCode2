class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
         unordered_set<long long> seen;
        long long prefix = 0;
        int count = 0;
        
        seen.insert(0); 
        
        for (int num : nums) {
            prefix += num;
            
            if (seen.count(prefix - target)) {
                count++;
                seen.clear(); 
                prefix = 0;  
                seen.insert(0);
            } else {
                seen.insert(prefix);
            }
        }
        return count;
    }
};