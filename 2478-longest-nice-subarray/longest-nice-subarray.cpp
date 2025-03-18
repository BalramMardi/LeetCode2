class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int left=0;
        int usedBits=0;
        int maxi = 0;

        for(int right=0;right<nums.size();right++){
            
            while((usedBits & nums[right])!=0){
                usedBits ^= nums[left];
                left++;
            }
            
            usedBits |= nums[right];
            maxi = max(maxi, right-left+1);
        }

        return maxi;
    }
};