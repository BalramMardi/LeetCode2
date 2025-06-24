class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> trimmed;

            for (int i = 0; i < nums.size(); ++i) {
                string trimmedStr = nums[i].substr(nums[i].size() - trim);
                trimmed.push_back({trimmedStr, i});
            }

            sort(trimmed.begin(), trimmed.end());

            ans.push_back(trimmed[k - 1].second);
        }

        return ans;
    }
};
