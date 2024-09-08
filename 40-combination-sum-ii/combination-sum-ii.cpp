class Solution {
public:
    void solve(vector<int>& can, int t, int idx, vector<vector<int>>& ans, vector<int>& path) {
        if (t < 0) {
            return; // no valid combination
        }
        if (t == 0) {
            ans.push_back(path); // valid combination found
            return;
        }

        // Base recursive case without for loop
        if (idx >= can.size()) {
            return;
        }

        // Include the current element and move to the next
        path.push_back(can[idx]);
        solve(can, t - can[idx], idx + 1, ans, path);
        path.pop_back(); // backtrack

        // Skip duplicates: move idx forward until the current element is no longer a duplicate
        int nextIdx = idx + 1;
        while (nextIdx < can.size() && can[nextIdx] == can[idx]) {
            nextIdx++;
        }

        // Exclude the current element and move to the next distinct element
        solve(can, t, nextIdx, ans, path);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, ans, path);
        return ans;
    }
};
