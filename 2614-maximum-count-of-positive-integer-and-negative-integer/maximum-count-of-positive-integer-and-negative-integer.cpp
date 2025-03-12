class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto zero = lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        auto firstPositive = upper_bound(nums.begin(),nums.end(),0)-nums.begin();

        int pos = nums.size()-firstPositive;
        int neg = zero;

        return max(pos,neg);
    }
    /* int maximumCount(vector<int>& nums) {
        int neg = 0;
        int pos = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                pos++;
            }
            else if(nums[i] < 0){
                neg++;
            }
            maxi =  max(pos,neg);
        }

        return maxi;
    } */
};