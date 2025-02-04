class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int osum=nums[0];
        int maxa=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                osum = osum+nums[i+1];
            }
            else{
                osum=nums[i+1];
            }
            maxa = max(maxa,osum);
        }
        return maxa;
    }
};