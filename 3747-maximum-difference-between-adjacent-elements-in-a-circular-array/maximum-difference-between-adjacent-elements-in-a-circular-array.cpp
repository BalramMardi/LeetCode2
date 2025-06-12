class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxa=INT_MIN;
        for(int i=0;i<n-1;i++){
            maxa = max(maxa,abs(nums[i]-nums[i+1]));
        }

        maxa = max(abs(nums[n-1]-nums[0]),maxa);

        return maxa;
    }
};