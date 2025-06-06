#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int dp0 = arr[0]; 
        int dp1 = 0;      
        int ans = arr[0];

        for (int i = 1; i < n; ++i) {
            dp1 = max(dp0, dp1 + arr[i]);      
            dp0 = max(arr[i], dp0 + arr[i]);   
            ans = max({ans, dp0, dp1});
        }

        return ans;
    }
};


/* #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<long long>> memo;

    long long dp(int i, int deleted) {
        if (i == n) return LLONG_MIN;
        if (memo[i][deleted] != LLONG_MIN) return memo[i][deleted];

        long long res = arr[i];

        long long extend = dp(i + 1, deleted);
        if (extend != LLONG_MIN)
            res = max(res, arr[i] + extend);

        if (!deleted) {
            long long skip = dp(i + 1, 1);
            res = max(res, skip);
        }

        return memo[i][deleted] = res;
    }

    int maximumSum(vector<int>& input) {
        arr = input;
        n = arr.size();
        memo.assign(n, vector<long long>(2, LLONG_MIN));

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp(i, 0));
        }
        return (int)ans;
    }
};
 */