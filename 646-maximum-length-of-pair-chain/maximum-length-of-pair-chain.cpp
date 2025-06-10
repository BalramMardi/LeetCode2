class Solution {
public:
    vector<vector<int>> pairs;
    int n;
    int dp[1001][1001];

    int solve(int curr, int prev) {
        if (curr == n) return 0;
        if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

        // Skip current
        int notTake = solve(curr + 1, prev);

        // Take current if it follows previous
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[curr][0]) {
            take = 1 + solve(curr + 1, curr);
        }

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& input) {
        pairs = input;
        n = pairs.size();
        sort(pairs.begin(), pairs.end()); 
        memset(dp, -1, sizeof(dp));
        return solve(0, -1);
    }
};


/* class Solution {
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
}; */



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