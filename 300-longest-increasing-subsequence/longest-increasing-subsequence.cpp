class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int omax=0; 
        vector<int> dp(nums.size());

        if(nums.size()==1){
            return 1;
        }

        dp[0]=1;
        for(int i = 1 ; i<dp.size() ; i++){
            int maxx = 0;
            for(int j=0; j < i ; j++){
                if(nums[j] < nums[i]){
                    maxx=max(dp[j],maxx);
                }
            }
            dp[i] = maxx +1;
            omax = max(dp[i],omax);
        }
        return omax;

        
    }
};