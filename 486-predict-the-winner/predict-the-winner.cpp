class Solution {
public:
    int solve(vector<int>&nums,int i,int j){
        if(i > j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        
        int sum = max(nums[i] + min(solve(nums,i+2,j),solve(nums,i+1,j-1)),nums[j] + min(solve(nums,i,j-2),solve(nums,i+1,j-1)));
        return sum;
    }

    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);

        int scoreA = solve(nums,0,nums.size()-1);

        return scoreA >= total-scoreA;
    }
};