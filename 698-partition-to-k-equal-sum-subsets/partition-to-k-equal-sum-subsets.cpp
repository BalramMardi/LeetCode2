class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        if(n == 0){
            return false;
        }
        vector<bool> dp(1<<n,false);
        vector<int> total(1<<n,0);
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        dp[0] = true;
        sort(nums.begin(),nums.end());
        if(sum % k != 0){
            return false;
        }
        sum /= k;

        if(nums[n-1] > sum){
            return false;
        }

        for(int i=0;i<(1<<n);i++){

            if(dp[i]){
                for(int j=0;j<n;j++){
                    int temp = i | (1<<j);
                        if(temp != i){
                            if(nums[j] <= (sum - total[i]%sum)){
                                dp[temp] = true;
                                total[temp] = nums[j] + total[i];
                            }
                            else{
                                break;
                            }
                        }
                }
            }
        }

        return dp[(1<<n)-1];

    }
};