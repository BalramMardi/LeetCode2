class Solution {
public:
    vector<vector<int>> pairs;
    int dp[1001];

    int solve(int i) {
        if (dp[i] != -1) return dp[i];

        int res = 1; 
        for (int j = 0; j < i; j++) {
            if (pairs[j][1] < pairs[i][0]) {
                res = max(res, 1 + solve(j));
            }
        }
        return dp[i] = res;
    }

    int findLongestChain(vector<vector<int>>& input) {
        pairs = input;
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            maxLen = max(maxLen, solve(i));
        }
        return maxLen;
    }
};



/* class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(begin(pairs), end(pairs));
        
        vector<int> t(n, 1);
        int maxL = 1;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                
                if(pairs[j][1] < pairs[i][0]) {
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        
        return maxL;
    }
};
 */