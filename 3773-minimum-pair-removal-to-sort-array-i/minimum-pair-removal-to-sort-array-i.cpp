class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int mini=INT_MAX;
            int pos=-1;
            for(int i=1;i<nums.size();i++){
                if(mini > (nums[i-1]+nums[i])){
                    mini = (nums[i-1]+nums[i]);
                    pos=i-1;
                }
            }
            vector<int> vec;
            for(int i=0;i<nums.size();i++){
                if(i==pos){
                    vec.push_back(mini);
                    continue;
                }
                else if(i==pos+1){
                    continue;
                }
                vec.push_back(nums[i]);
            }

            nums=vec;
            count++;
        }

        return count;

    }
};