class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mini = 1e9;
        int ans=0;

        vector<int> vec(n,1);
        vector<int> dp(budget+1,0);

        for(int i=0;i<n;i++){
            mini = min(mini, items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0){
                    vec[i]++;
                }
            }
        }

        
        for(int i=0;i<n;i++){
            for(int w=budget;w >= items[i][1];w--){
                dp[w] = max(dp[w],dp[w-items[i][1]] + vec[i]);
            }
        }

        for(int w=0;w<=budget ;w++){
            ans = max(dp[w]+(budget-w)/mini , ans);
        }

        return ans;
    }
};