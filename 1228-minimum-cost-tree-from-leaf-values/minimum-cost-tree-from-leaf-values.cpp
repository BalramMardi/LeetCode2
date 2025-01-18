class Solution {
public:
    
    int solve(vector<int>&arr, map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>> &dp){
        if(left == right){
            return 0;
        }

        if(dp[left][right]!=-1) return dp[left][right];
        int ans = INT_MAX;
        for(int k=left;k<right;k++){
            ans = min(ans,maxi[{left,k}]* maxi[{k+1,right}]+solve(arr,maxi,left,k,dp)+solve(arr,maxi,k+1,right,dp));
        }

        return dp[left][right] = ans;
    }


    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        map<pair<int,int>,int> maxi;

        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            int mm = arr[i];
            for(int j=i;j<n;j++){
                mm = max(mm,arr[j]);
                maxi[{i,j}]=mm;
            }
        }

        return solve(arr,maxi,0,n-1,dp);


    }
};