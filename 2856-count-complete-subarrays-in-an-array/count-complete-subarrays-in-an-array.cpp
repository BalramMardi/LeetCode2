class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        
        unordered_map<int, int> freq; 
        int res = 0;
        int left = 0;
        int distinctInWindow = 0;

        for (int right = 0; right < n; ++right) {

            if (++freq[nums[right]] == 1)
                distinctInWindow++;

            
            while (distinctInWindow == totalDistinct) {
                if (--freq[nums[left]] == 0)
                    distinctInWindow--;
                left++;
            }

            res += left;
        }

        return res;
    }

};