class Solution {
public:
    int n;
    unordered_map<vector<bool>,int>mp;
    int solve(vector<int>&nums,vector<bool>vis,int op){
        
        int maxScore = 0;
        
        if(mp.find(vis)!=mp.end()){
            return mp[vis];
        }
        for(int i=0;i<n-1;i++){
            if(vis[i]) continue;
            for(int j=i+1;j<n;j++){
                if(vis[j]) continue;

                vis[i]=true;
                vis[j]=true;

                int curr =op *  __gcd(nums[i],nums[j]);
                int remScore = solve(nums,vis,op+1);
                maxScore=max(maxScore,curr+remScore);

                vis[i]=false;
                vis[j]=false;
            }
        }

        return mp[vis]= maxScore;
    }

    int maxScore(vector<int>& nums) {
         n=nums.size();
        
        vector<bool> vis(n,false);

        return solve(nums,vis,1);

    }
};