class Solution {
public:
    int memo[50001];
    int n;

    // Find the first job where the starting point >= currentJob end point
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n; // set result to n, not n + 1
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) { // valid next job
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n)
            return 0;
        
        if (memo[i] != -1)
            return memo[i];
        
        int next = getNextIndex(array, i + 1, array[i][1]);
        int taken = array[i][2] + solve(array, next); // taking this job
        int notTaken = solve(array, i + 1); // skipping this job
        
        return memo[i] = max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(memo, -1, sizeof(memo)); // initialize memo array to -1
        
        // Store jobs as {startTime, endTime, profit}
        vector<vector<int>> array(n, vector<int>(3, 0)); 
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        // Sort by start time
        sort(begin(array), end(array), [](auto& vec1, auto& vec2) {
            return vec1[0] < vec2[0];
        });
        
        return solve(array, 0); // start from the 0th job
    }
};
