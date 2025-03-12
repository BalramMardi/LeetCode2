class Solution {
public:
    int maximumCount(vector<int>& nums) {
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
    }
};