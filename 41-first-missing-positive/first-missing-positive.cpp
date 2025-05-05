class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        bool hasOne = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                hasOne = true;
            }

            if(nums[i] <= 0 || nums[i] > nums.size()){
                nums[i] = 1;
            }
        }

        if(!hasOne){
            return 1;
        }

        for(int i=0;i<nums.size();i++){

            int val = abs(nums[i]);
            
            if(val == nums.size()){
                nums[0] = -abs(nums[0]);
            }
            else{
                nums[val] = -abs(nums[val]);
            }
        }

        int ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > 0){
                return i;
            }
        }


        if(nums[0] > 0){
            return nums.size();
        }

        return nums.size()+1;
    }
};