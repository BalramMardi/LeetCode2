class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftMax(n),rightMax(n);
        for(int i=1;i<n;i++){
            leftMax[i]= max(leftMax[i-1],nums[i-1]);
            rightMax[n-i-1]=max(rightMax[n-i],nums[n-i]);
        }
        long long ans=0LL;
        for(int i=1;i<n-1;i++){
            long long sum = (long long)(leftMax[i]-nums[i])*rightMax[i];
            ans = max(ans,sum);
        }
        
        return ans;
    }
};