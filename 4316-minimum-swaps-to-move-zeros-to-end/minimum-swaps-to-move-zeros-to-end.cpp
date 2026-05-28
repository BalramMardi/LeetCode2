class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        
        int nt=0;
        for(int i=nums.size()-cnt;i<nums.size();i++){
            if(nums[i]!=0){
                nt++;
            }
        }
        return nt;
    }
};