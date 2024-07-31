class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {     
        int ominsum=nums[0];
        int cminsum = nums[0];

        int omaxsum=nums[0];
        int cmaxsum = nums[0];

        int fullsum = accumulate(nums.begin(),nums.end(),0);

        for(int i=1;i<nums.size();i++){
            
             ominsum = min((ominsum+nums[i]),nums[i]);
             cminsum = min(ominsum , cminsum);

             omaxsum = max((omaxsum+nums[i]),nums[i]);
             cmaxsum = max(omaxsum , cmaxsum);
        }

        

        return cmaxsum > 0 ? max((fullsum - cminsum),cmaxsum) : cmaxsum ;
    }
};