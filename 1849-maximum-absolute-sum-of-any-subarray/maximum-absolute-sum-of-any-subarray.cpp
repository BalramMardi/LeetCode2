class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int overallPositive=0,currPositive=0,overallNegative=0,currNegative=0;

       for(int i=0;i<nums.size();i++){
            currPositive = max(nums[i], currPositive+nums[i]);
            overallPositive = max(currPositive,overallPositive);
            
            currNegative = min(nums[i], currNegative+nums[i]);
            overallNegative = min(currNegative,overallNegative);
       } 

        return max(overallPositive, abs(overallNegative));
    }
};