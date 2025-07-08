class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
        return dfs(0, k, events);
    }

private:
    vector<vector<int>> dp;
    int n;

    int dfs(int curIndex, int count, vector<vector<int>>& events) {
        if (count == 0 || curIndex == n) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }

        auto it = upper_bound(events.begin() + curIndex + 1, events.end(), events[curIndex][1], 
            [](int value, const vector<int>& event) {
                return value < event[0];
            });
        
        int nextIndex = distance(events.begin(), it);
        
        int skip = dfs(curIndex + 1, count, events);
        int take = events[curIndex][2] + dfs(nextIndex, count - 1, events);
        
        return dp[count][curIndex] = max(skip, take);
    }
};



/* class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        n = events.size();
        dp = vector<vector<int>>(k + 1, vector<int>(n, -1));
        return dfs(0, k, events);
    }

private:
    vector<vector<int>> dp;
    int n;

    int dfs(int curIndex, int count, vector<vector<int>>& events) {
        if (count == 0 || curIndex == n) {
            return 0;
        }
        if (dp[count][curIndex] != -1) {
            return dp[count][curIndex];
        }
        int nextIndex = bisectRight(events, events[curIndex][1]);
        int skip = dfs(curIndex + 1, count, events);
        int take = events[curIndex][2] + dfs(nextIndex, count - 1, events);
        dp[count][curIndex] = max(skip, take);
        return dp[count][curIndex];
    }

    int bisectRight(vector<vector<int>>& events, int target) {
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
 */