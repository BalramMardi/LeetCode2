class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxi = *max_element(nums.begin(),nums.end());
        int n=nums.size();
        int left=0,right=0;
        int len=0;

        while(right<n){
            if(nums[right]==maxi){
                right++;
                len = max(len , (right-left));
            }
            else{
                right++;
                left=right;
            }
        }

        return len;
    }
};