class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vec;
        for(int i=0;i<scores.size();i++){
            vec.push_back({ages[i],scores[i]});
        }

        sort(vec.begin(),vec.end());

        vector<int> dp(vec.size());
        dp[0]=vec[0].second;

        int omax=0;
        for(int i=1;i<vec.size();i++){
            dp[i]=vec[i].second;
            int maxx = 0;
            for(int j=0;j<i;j++){
                if(vec[j].second <= vec[i].second){
                    maxx = max(dp[j] , maxx );
                }
            }

            dp[i] += maxx;
        }

        omax = *max_element(dp.begin(),dp.end());

        return omax;
    }
};