class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int> ans(n);
        ans[0]=cost[0];
        for(int i=1;i<n;i++){
            ans[i]=min(ans[i-1],cost[i]);
        }
        return ans;
    }
};