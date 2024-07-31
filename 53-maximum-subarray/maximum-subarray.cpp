class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int csum=nums[0];
        int osum=nums[0];

        for(int i=1;i<nums.size();i++){
            csum = max(csum+nums[i],nums[i]);
            osum = max(osum,csum);
        }
        return osum;
    }
};