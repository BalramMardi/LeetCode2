class Solution {
public:
    int memo[501][501];
    int solve(vector<int>&nums1, vector<int>&nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        if(nums1[i]==nums2[j])
            return memo[i][j] =  1+solve(nums1,nums2,i+1,j+1);

        int fix_i = solve(nums1,nums2,i,j+1);
        int fix_j = solve(nums1,nums2,i+1,j);

        return  memo[i][j]=  max(fix_i,fix_j);

    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(memo,-1,sizeof(memo));
        return solve(nums1,nums2,0,0);
    }
};